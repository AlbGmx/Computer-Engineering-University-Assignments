let bool = 0;
let timeStart = 0;
let timeEnd = 0;
const reactionContainer = document.querySelector('.reaction-container');
//Add text to the container
reactionContainer.innerHTML = '<h1>Click when the background turns green</h1>';
//Make the container clickable
reactionContainer.addEventListener('click', function () {   
   if (bool === 0) {
      changeColor("red");
      bool = 1;
   }
   else if (bool === 1) {
      //wait a random amount of time between 1 and 3 seconds
      let randomTime = Math.floor(Math.random() * (3000 - 1000 + 1)) + 1000;
      setTimeout(function () {
         changeColor("green");
         reactionContainer.innerHTML = '<h1></h1>';
         flag = false;
      }
         , randomTime);
      //set timeStart to the current time
      timeStart = new Date().getTime();
      bool = 2;
   }
   else {
      //set timeEnd to the current time
      timeEnd = new Date().getTime();
      //calculate the reaction time
      let reactionTime = timeEnd - timeStart;
      //add the reaction time to the container
      reactionContainer.innerHTML = '<h1>Your reaction time was ' + reactionTime + ' milliseconds</h1>';
      //reset the bool to 0
      bool = 0;
   }
}
);


function changeColor(color) {
   reactionContainer.style.backgroundColor = color;
}



