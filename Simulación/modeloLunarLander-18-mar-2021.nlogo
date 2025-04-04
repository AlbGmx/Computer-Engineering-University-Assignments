globals [
  platform     ;; the x coordinate of the center of the platform
]

turtles-own [
  xvel yvel    ;; x and y components of the lander's velocity
]

to setup
  clear-all
  setup-terrain
  create-turtles 1 [
    set shape "lander"
    set color red
    set size 10
    setxy (platform + max-pxcor)
          (max-pycor - size / 2)
    set heading 0
  ]
  reset-ticks
end

to setup-terrain
  let terrain-color gray
  set platform platform-width
               + random (world-width - 2 * platform-width)
               + min-pxcor
  ;; first use a turtle to draw the surface of the moon
  ;; including the landing platform
  create-turtles 1 [
    set color gray
    setxy min-pxcor
          floor (min-pycor / 2)
    set heading 90
    repeat world-width [
      set pcolor color
      fd 1
      ;; draw the platform in blue
      if pxcor = platform - (platform-width / 2) [
        set heading 90
        set color blue
      ]
      ;; everything else is moon surface and should be gray
      if pxcor = platform + (platform-width / 2) [
        set color gray
      ]
      ;; and if it isn't the platform it should also be
      ;; jagged so vary ycor by the terrain-bumpiness
      if color != blue [
        ;; random-poisson usually gives small variations, occasionally
        ;; larger ones
        let y ( ycor + one-of [1 -1] * random-poisson ( terrain-bumpiness ) )
        ;; prevent the drawing turtle from wrapping vertically
        ;; while contouring the terrain
          if patch-at 0 (y - ycor) != nobody
          [ set ycor y ]
      ]
    ]
    die
  ]

  ;; then use more turtles to make solid gray below the gray line
  ask patches with [pcolor != black] [
    sprout 1 [
      set heading 180
      ;; if the drawing turtle is already at the bottom it should not continue
      if not can-move? 1 [ die ]
      fd 1
      set pcolor gray
      fd 1
      while [ can-move? 1 ]
      [
        set pcolor gray
        fd 1
      ]
      set pcolor gray
      die
    ]
  ]
end

to go
  if (not any? turtles) or ([color] of one-of turtles != red)
    [ stop ]
  ask turtles [
    ;; if the module is about to wrap vertically
    ;; stop its ascent
    ifelse ycor + yvel > max-pycor
    [ set xcor (xcor + xvel)
      set yvel 0 ]
    [ setxy (xcor + xvel) (ycor + yvel) ]
    ;; exert the force of gravity
    set yvel yvel - 0.001
    ;; detect crashes and insufficiently soft landings
    if [pcolor] of patch-at 0 -2 != black [
      ifelse (abs yvel > 0.08) or
             (abs xvel > 0.04) or
             (heading != 0) or
             ((pxcor - platform) >= platform-width / 2)
      [ game-over ]
      [ set color green - 1 ]
    ]
    ;; switch back to the shape without the thrusters on
    if shape = "lander2" and timer > 0.3
      [ set shape "lander" ]
  ]
  tick
end

to game-over  ;; turtle procedure
  set shape "skull"
  set color white
  set heading 0
end

to rotate-left  ;; turtle procedure
  if shape = "lander" [
    lt 5
  ]
end

to rotate-right  ;; turtle procedure
  if shape = "lander" [
    rt 5
  ]
end

to thrust  ;; turtle procedure
  if shape = "lander" [
    set xvel xvel + thrust-amount * dx
    set yvel yvel + thrust-amount * dy
    ;; lander2 has a visual indication that the thrusters are on
    set shape "lander2"
    reset-timer
  ]
end

to land
  if shape = "lander" [
    set shape "lander2"
    reset-timer
    set heading 0
    set xvel 0
    set yvel -.06
  ]
end



; Copyright 2005 Uri Wilensky.
; See Info tab for full copyright and license.
@#$#@#$#@
GRAPHICS-WINDOW
248
10
761
524
-1
-1
5.0
1
10
1
1
1
0
1
0
1
-50
50
-50
50
1
1
1
ticks
67.0

BUTTON
43
106
109
139
NIL
setup
NIL
1
T
OBSERVER
NIL
S
NIL
NIL
1

BUTTON
125
106
191
139
NIL
go
T
1
T
OBSERVER
NIL
G
NIL
NIL
0

BUTTON
13
240
78
273
left
rotate-left
NIL
1
T
TURTLE
NIL
J
NIL
NIL
0

BUTTON
83
241
153
274
NIL
thrust
NIL
1
T
TURTLE
NIL
K
NIL
NIL
0

BUTTON
158
241
222
274
right
rotate-right
NIL
1
T
TURTLE
NIL
L
NIL
NIL
0

TEXTBOX
20
154
215
231
Land on the blue landing pad!\n\nYou must land straight,\nand land very gently.
11
0.0
0

SLIDER
30
26
202
59
platform-width
platform-width
4.0
20.0
20.0
2.0
1
NIL
HORIZONTAL

SLIDER
30
61
202
94
terrain-bumpiness
terrain-bumpiness
0.0
10.0
3.0
1.0
1
NIL
HORIZONTAL

SLIDER
32
285
204
318
thrust-amount
thrust-amount
0.0
1.0
0.15
0.01
1
NIL
HORIZONTAL

BUTTON
84
328
154
361
NIL
land\n
T
1
T
TURTLE
NIL
NIL
NIL
NIL
1

@#$#@#$#@
## WHAT IS IT?

This model is based on the arcade game, Lunar Lander.  The object of the game is to land the red lunar module on the blue landing pad on the surface of the moon without crashing or breaking the module.

The lunar module is fragile, so you have to be moving extremely slowly to prevent damage when you touch down. You have one thruster that exerts a force depending on the tilt of the module.  You have the ability to tilt right and left.

## HOW TO USE IT

Buttons:
SETUP starts the game over by creating a new surface for you to navigate and poising your module above that surface, ready for descent.
GO starts the game.  Be ready; the module will start descending fairly quickly.
LEFT and RIGHT tilt the module back and forth
THRUST fires your rockets according to your current tilt.

Sliders:
PLATFORM-WIDTH controls the width of the blue landing pad created at setup, a wider landing pad makes an easier target.
TERRAIN-BUMPINESS controls the variation in the elevation of the lunar surface.  More bumpiness may mean you will have large obstacles to maneuver around.
THRUST-AMOUNT controls the magnitude of the force of your rockets.

## THINGS TO NOTICE

When terrain-bumpiness is very high some of the randomly generated surfaces are not navigable.

## THINGS TO TRY

Try to land the module with the fewest adjustments.

Increase the THRUST-AMOUNT to make the game harder.

## EXTENDING THE MODEL

Add one or more plots to the model. For example, you might plot the position, velocity, and/or acceleration of the module, in the plane or just on the Y axis.

Currently, collisions with the edges of the module are not detected, so you can graze the side of a peak with the edge of the module without crashing.  It would be more realistic if these crashes were detected.

Add levels to the game by continually making the terrain bumpier, the platform smaller, or by some other method of making the game more difficult, perhaps alien spaceships.

Try to write a robot pilot that will automatically land the module safely.

## NETLOGO FEATURES

This model uses the `random-poisson` reporter to create the terrain.  See its entry in the NetLogo Dictionary, and also http://mathworld.wolfram.com/PoissonDistribution.html.

The frame rate setting is used to control the speed of the game.

## RELATED MODELS

* Projectile Attack
* Gravitation

## HOW TO CITE

If you mention this model or the NetLogo software in a publication, we ask that you include the citations below.

For the model itself:

* Wilensky, U. (2005).  NetLogo Lunar Lander model.  http://ccl.northwestern.edu/netlogo/models/LunarLander.  Center for Connected Learning and Computer-Based Modeling, Northwestern University, Evanston, IL.

Please cite the NetLogo software as:

* Wilensky, U. (1999). NetLogo. http://ccl.northwestern.edu/netlogo/. Center for Connected Learning and Computer-Based Modeling, Northwestern University, Evanston, IL.

## COPYRIGHT AND LICENSE

Copyright 2005 Uri Wilensky.

![CC BY-NC-SA 3.0](http://ccl.northwestern.edu/images/creativecommons/byncsa.png)

This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 License.  To view a copy of this license, visit https://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.

Commercial licenses are also available. To inquire about commercial licenses, please contact Uri Wilensky at uri@northwestern.edu.

<!-- 2005 -->
@#$#@#$#@
default
true
0
Polygon -7500403 true true 150 5 40 250 150 205 260 250

airplane
true
0
Polygon -7500403 true true 150 0 135 15 120 60 120 105 15 165 15 195 120 180 135 240 105 270 120 285 150 270 180 285 210 270 165 240 180 180 285 195 285 165 180 105 180 60 165 15

arrow
true
0
Polygon -7500403 true true 150 0 0 150 105 150 105 293 195 293 195 150 300 150

box
false
0
Polygon -7500403 true true 150 285 285 225 285 75 150 135
Polygon -7500403 true true 150 135 15 75 150 15 285 75
Polygon -7500403 true true 15 75 15 225 150 285 150 135
Line -16777216 false 150 285 150 135
Line -16777216 false 150 135 15 75
Line -16777216 false 150 135 285 75

bug
true
0
Circle -7500403 true true 96 182 108
Circle -7500403 true true 110 127 80
Circle -7500403 true true 110 75 80
Line -7500403 true 150 100 80 30
Line -7500403 true 150 100 220 30

butterfly
true
0
Polygon -7500403 true true 150 165 209 199 225 225 225 255 195 270 165 255 150 240
Polygon -7500403 true true 150 165 89 198 75 225 75 255 105 270 135 255 150 240
Polygon -7500403 true true 139 148 100 105 55 90 25 90 10 105 10 135 25 180 40 195 85 194 139 163
Polygon -7500403 true true 162 150 200 105 245 90 275 90 290 105 290 135 275 180 260 195 215 195 162 165
Polygon -16777216 true false 150 255 135 225 120 150 135 120 150 105 165 120 180 150 165 225
Circle -16777216 true false 135 90 30
Line -16777216 false 150 105 195 60
Line -16777216 false 150 105 105 60

car
false
0
Polygon -7500403 true true 300 180 279 164 261 144 240 135 226 132 213 106 203 84 185 63 159 50 135 50 75 60 0 150 0 165 0 225 300 225 300 180
Circle -16777216 true false 180 180 90
Circle -16777216 true false 30 180 90
Polygon -16777216 true false 162 80 132 78 134 135 209 135 194 105 189 96 180 89
Circle -7500403 true true 47 195 58
Circle -7500403 true true 195 195 58

circle
false
0
Circle -7500403 true true 0 0 300

circle 2
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240

cow
false
0
Polygon -7500403 true true 200 193 197 249 179 249 177 196 166 187 140 189 93 191 78 179 72 211 49 209 48 181 37 149 25 120 25 89 45 72 103 84 179 75 198 76 252 64 272 81 293 103 285 121 255 121 242 118 224 167
Polygon -7500403 true true 73 210 86 251 62 249 48 208
Polygon -7500403 true true 25 114 16 195 9 204 23 213 25 200 39 123

cylinder
false
0
Circle -7500403 true true 0 0 300

dot
false
0
Circle -7500403 true true 90 90 120

face happy
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 255 90 239 62 213 47 191 67 179 90 203 109 218 150 225 192 218 210 203 227 181 251 194 236 217 212 240

face neutral
false
0
Circle -7500403 true true 8 7 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Rectangle -16777216 true false 60 195 240 225

face sad
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 168 90 184 62 210 47 232 67 244 90 220 109 205 150 198 192 205 210 220 227 242 251 229 236 206 212 183

fish
false
0
Polygon -1 true false 44 131 21 87 15 86 0 120 15 150 0 180 13 214 20 212 45 166
Polygon -1 true false 135 195 119 235 95 218 76 210 46 204 60 165
Polygon -1 true false 75 45 83 77 71 103 86 114 166 78 135 60
Polygon -7500403 true true 30 136 151 77 226 81 280 119 292 146 292 160 287 170 270 195 195 210 151 212 30 166
Circle -16777216 true false 215 106 30

flag
false
0
Rectangle -7500403 true true 60 15 75 300
Polygon -7500403 true true 90 150 270 90 90 30
Line -7500403 true 75 135 90 135
Line -7500403 true 75 45 90 45

flower
false
0
Polygon -10899396 true false 135 120 165 165 180 210 180 240 150 300 165 300 195 240 195 195 165 135
Circle -7500403 true true 85 132 38
Circle -7500403 true true 130 147 38
Circle -7500403 true true 192 85 38
Circle -7500403 true true 85 40 38
Circle -7500403 true true 177 40 38
Circle -7500403 true true 177 132 38
Circle -7500403 true true 70 85 38
Circle -7500403 true true 130 25 38
Circle -7500403 true true 96 51 108
Circle -16777216 true false 113 68 74
Polygon -10899396 true false 189 233 219 188 249 173 279 188 234 218
Polygon -10899396 true false 180 255 150 210 105 210 75 240 135 240

house
false
0
Rectangle -7500403 true true 45 120 255 285
Rectangle -16777216 true false 120 210 180 285
Polygon -7500403 true true 15 120 150 15 285 120
Line -16777216 false 30 120 270 120

lander
true
0
Polygon -7500403 true true 45 75 150 30 255 75 285 225 240 225 240 195 210 195 210 225 165 225 165 195 135 195 135 225 90 225 90 195 60 195 60 225 15 225 45 75

lander2
true
0
Polygon -7500403 true true 45 75 150 30 255 75 285 225 240 225 240 195 210 195 210 225 165 225 165 195 135 195 135 225 90 225 90 195 60 195 60 225 15 225 45 75
Line -1 false 75 210 75 270
Line -1 false 150 210 150 285
Line -1 false 225 210 225 270

leaf
false
0
Polygon -7500403 true true 150 210 135 195 120 210 60 210 30 195 60 180 60 165 15 135 30 120 15 105 40 104 45 90 60 90 90 105 105 120 120 120 105 60 120 60 135 30 150 15 165 30 180 60 195 60 180 120 195 120 210 105 240 90 255 90 263 104 285 105 270 120 285 135 240 165 240 180 270 195 240 210 180 210 165 195
Polygon -7500403 true true 135 195 135 240 120 255 105 255 105 285 135 285 165 240 165 195

line
true
0
Line -7500403 true 150 0 150 300

line half
true
0
Line -7500403 true 150 0 150 150

pentagon
false
0
Polygon -7500403 true true 150 15 15 120 60 285 240 285 285 120

person
false
0
Circle -7500403 true true 110 5 80
Polygon -7500403 true true 105 90 120 195 90 285 105 300 135 300 150 225 165 300 195 300 210 285 180 195 195 90
Rectangle -7500403 true true 127 79 172 94
Polygon -7500403 true true 195 90 240 150 225 180 165 105
Polygon -7500403 true true 105 90 60 150 75 180 135 105

plant
false
0
Rectangle -7500403 true true 135 90 165 300
Polygon -7500403 true true 135 255 90 210 45 195 75 255 135 285
Polygon -7500403 true true 165 255 210 210 255 195 225 255 165 285
Polygon -7500403 true true 135 180 90 135 45 120 75 180 135 210
Polygon -7500403 true true 165 180 165 210 225 180 255 120 210 135
Polygon -7500403 true true 135 105 90 60 45 45 75 105 135 135
Polygon -7500403 true true 165 105 165 135 225 105 255 45 210 60
Polygon -7500403 true true 135 90 120 45 150 15 180 45 165 90

skull
true
0
Circle -7500403 true true 45 15 210
Rectangle -7500403 true true 90 180 210 270
Circle -16777216 true false 84 84 42
Circle -16777216 true false 174 84 42
Line -16777216 false 105 225 195 225
Line -16777216 false 120 210 120 240
Line -16777216 false 195 210 195 240
Line -16777216 false 150 210 150 240
Line -16777216 false 165 210 165 240
Line -16777216 false 180 210 180 240
Line -16777216 false 135 210 135 240
Line -16777216 false 105 210 105 240
Polygon -16777216 true false 150 135 135 180 165 180 150 135

square
false
0
Rectangle -7500403 true true 30 30 270 270

square 2
false
0
Rectangle -7500403 true true 30 30 270 270
Rectangle -16777216 true false 60 60 240 240

star
false
0
Polygon -7500403 true true 151 1 185 108 298 108 207 175 242 282 151 216 59 282 94 175 3 108 116 108

target
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240
Circle -7500403 true true 60 60 180
Circle -16777216 true false 90 90 120
Circle -7500403 true true 120 120 60

tree
false
0
Circle -7500403 true true 118 3 94
Rectangle -6459832 true false 120 195 180 300
Circle -7500403 true true 65 21 108
Circle -7500403 true true 116 41 127
Circle -7500403 true true 45 90 120
Circle -7500403 true true 104 74 152

triangle
false
0
Polygon -7500403 true true 150 30 15 255 285 255

triangle 2
false
0
Polygon -7500403 true true 150 30 15 255 285 255
Polygon -16777216 true false 151 99 225 223 75 224

truck
false
0
Rectangle -7500403 true true 4 45 195 187
Polygon -7500403 true true 296 193 296 150 259 134 244 104 208 104 207 194
Rectangle -1 true false 195 60 195 105
Polygon -16777216 true false 238 112 252 141 219 141 218 112
Circle -16777216 true false 234 174 42
Rectangle -7500403 true true 181 185 214 194
Circle -16777216 true false 144 174 42
Circle -16777216 true false 24 174 42
Circle -7500403 false true 24 174 42
Circle -7500403 false true 144 174 42
Circle -7500403 false true 234 174 42

turtle
true
0
Polygon -10899396 true false 215 204 240 233 246 254 228 266 215 252 193 210
Polygon -10899396 true false 195 90 225 75 245 75 260 89 269 108 261 124 240 105 225 105 210 105
Polygon -10899396 true false 105 90 75 75 55 75 40 89 31 108 39 124 60 105 75 105 90 105
Polygon -10899396 true false 132 85 134 64 107 51 108 17 150 2 192 18 192 52 169 65 172 87
Polygon -10899396 true false 85 204 60 233 54 254 72 266 85 252 107 210
Polygon -7500403 true true 119 75 179 75 209 101 224 135 220 225 175 261 128 261 81 224 74 135 88 99

wheel
false
0
Circle -7500403 true true 3 3 294
Circle -16777216 true false 30 30 240
Line -7500403 true 150 285 150 15
Line -7500403 true 15 150 285 150
Circle -7500403 true true 120 120 60
Line -7500403 true 216 40 79 269
Line -7500403 true 40 84 269 221
Line -7500403 true 40 216 269 79
Line -7500403 true 84 40 221 269

x
false
0
Polygon -7500403 true true 270 75 225 30 30 225 75 270
Polygon -7500403 true true 30 75 75 30 270 225 225 270
@#$#@#$#@
NetLogo 6.2.0
@#$#@#$#@
random-seed 1
setup
@#$#@#$#@
@#$#@#$#@
@#$#@#$#@
@#$#@#$#@
default
0.0
-0.2 0 0.0 1.0
0.0 1 1.0 0.0
0.2 0 0.0 1.0
link direction
true
0
Line -7500403 true 150 150 90 180
Line -7500403 true 150 150 210 180
@#$#@#$#@
0
@#$#@#$#@
