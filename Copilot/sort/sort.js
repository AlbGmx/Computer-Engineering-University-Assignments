var c = document.getElementById("C");
var ctx = c.getContext("2d");
var cw = c.width = c.clientWidth;
var ch = c.height  = c.clientHeight-200;
var size = cw;
var nums = [size];
var sorted = false;
//stroke bolder
ctx.lineWidth = 2;
var i = 0;
var j = 0;
var speed = 0;
var flag = false


//initialize array with random numbers
function initialize() {
   for (var i = 0; i < size; i++) {
      nums[i] = Math.floor(Math.random() * ch);
   }
   sorted = false;
   drawRects(nums, size, "red"); 
   i = 0;
   j = 0;
   speed = 5;
}

function drawRects(nums, size, color) {
   ctx.clearRect(0, 0, cw, ch);
   for (var i = 0; i < size; i++) {
      ctx.fillStyle = color;
      ctx.fillRect(i * cw / size, ch - nums[i], cw / size, nums[i]);
   }
}

function animateBubbleSort() {
   for (j = i; j < i+ speed; j++){
      for (var k = j + 1; k < size; k++){
         if (nums[j] > nums[k]) {
            var temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
         }
      }
   }  
   i += speed;
   if (i >= size) sorted = true;
   drawRects(nums, size, sorted ? "green" : "red");
   requestAnimationFrame(animateBubbleSort);
}
function animateCocktailSort() {
   flag = false;
   for (i=0; i < size; i++) {
      if(nums[i] > nums[i+1]) {
         var temp = nums[i];
         nums[i] = nums[i+1];
         nums[i + 1] = temp;
         flag = true;
      }
   }
   for (i = size - 2; i > 0; i--) {
      if(nums[i] > nums[i+1]) {
         var temp = nums[i];
         nums[i] = nums[i+1];
         nums[i + 1] = temp;
         flag = true;
      }
   }
   if (!flag) {
      sorted = true;
   }

drawRects(nums, size, sorted ? "green" : "red");
requestAnimationFrame(animateCocktailSort);
}
initialize();

//create a button to start the animation bubble sort an another for cocktail sort
var bubbleSort = document.getElementById("sortBubble");
bubbleSort.addEventListener("click", function () {
   i = 0;
   j = 0;

   requestAnimationFrame(animateBubbleSort);
});
var cocktailSort = document.getElementById("sortCocktail");
cocktailSort.addEventListener("click", function () {
   animateCocktailSort();
}
);
//Create a button to reset the animation
var reset = document.getElementById("resetArray");
reset.addEventListener("click", function () {
   sorted = false;
   //stop animations
   cancelAnimationFrame(animateBubbleSort);
   cancelAnimationFrame(animateCocktailSort);
   initialize();

}
);

