DDRx (Data Direction Register) = Direction
PORTx                                              = Register OUT
PINx                                                  = Register IN

1 es salida

PA6 <- Entrada 
PA3 -> Salida

DDRA |= (1<<PA6)
DDRA &= ~(1<<PA3)

`PORTA = (PINA >> (PA6-PA3)) ? (PORTA  | (1<<PA3)) :
`(PORTA & ~(1<<PA3))`
