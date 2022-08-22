const pokemonCardContainer = document.querySelector(".pokemon-card-container");

//Get the ?=id= parameter from the URL
const getId = () => {
   let url = new URL(window.location.href);
   let id = url.searchParams.get("id");
   return id;
}

//Fetch the pokemon data from the API with the id given
function fetchPokemon(id) {
   fetch(`https://pokeapi.co/api/v2/pokemon/${id}`)
      .then((res) => res.json())
      .then((data) => {
         createPokemonCard(data);
      });
}

//Function to create the pokemon card
function createPokemonCard (pokemon) {
   const pokemonCard = document.createElement('div');
   pokemonCard.classList.add('pokemon-card');

      
   const imgContainer = document.createElement('div');
   imgContainer.classList.add('img-container');
      
   const img = document.createElement('img');
   img.src = pokemon.sprites.front_default; 
   imgContainer.appendChild(img);
   
   //Add the number and name of the pokeon to the card
   const number = document.createElement('div');
   number.classList.add('extra-container');
   number.textContent = `#${pokemon.id.toString().padStart(3, '0')}`;
   const name = document.createElement('div');
   name.classList.add('extra-container');
   name.textContent = pokemon.name;

   //Add the info of the pokemon to the card
   const height = document.createElement('div');
   height.classList.add('extra-container');
   height.textContent = `Height: ${pokemon.height/10}` + `m ` + `   Weight: ${pokemon.weight/10}` + `kg`;

   //Add the types of the pokemon to the card
   const types = document.createElement('div');
   types.classList.add('extra-container');
   types.textContent = `Types:  ${pokemon.types.map(type => type.type.name).join(', ')}`;
   
   //Add the abilities of the pokemon to the card
   const abilities = document.createElement('div');
   abilities.classList.add('extra-container');
   abilities.textContent = `Abilities: ${pokemon.abilities.map(ability => ability.ability.name).join(', ')}`;

   /*Make the card clickable*/
   pokemonCard.addEventListener('click', () => {
      window.location.href = `./pokemon.html?id=${pokemon.id}`;
   }
   );
   

   /*Insert image on top of page*/
   pokemonCard.appendChild(imgContainer);   
   pokemonCard.appendChild(number);
   pokemonCard.appendChild(name);
   pokemonCard.appendChild(height);
   pokemonCard.appendChild(types);
   pokemonCard.appendChild(abilities);
   pokemonCardContainer.appendChild(pokemonCard);
}
const id = getId();
//If the id is 1, dont fetch the previous pokemon
if (id != 1) {
   fetchPokemon(id - 1);
}
fetchPokemon(id);
//If the id is the last pokemon, dont fetch the next pokemon
if (id != 905) {
   fetchPokemon(parseInt(id) + 1);
}


//Create a next button to go to the next pokemon
const nextButton = document.createElement('button');
nextButton.textContent = "Next";
nextButton.addEventListener('click', () => {
   window.location.href = `pokemon.html?id=${parseInt(getId()) + 1}`;
}
);
//Create a previous button to go to the previous pokemon
const previousButton = document.createElement('button');
previousButton.textContent = "Prev";
previousButton.addEventListener('click', () => {
   window.location.href = `pokemon.html?id=${parseInt(getId()) - 1}`;
}
);
//Create a button to go to the first pokemon
const firstButton = document.createElement('button');
firstButton.textContent = "First";
firstButton.addEventListener('click', () => {
   window.location.href = `pokemon.html?id=1`;
}
);
//Create a button to go to the last pokemon
const lastButton = document.createElement('button');
lastButton.textContent = "Last";
lastButton.addEventListener('click', () => {
   window.location.href = `pokemon.html?id=905`;
}
);
//Create a button to go to the home page
const homeButton = document.createElement('button');
homeButton.textContent = "Home";
homeButton.addEventListener('click', () => {
   window.location.href = "index.html";
}
);
const buttons = document.createElement('div');
buttons.classList.add('buttons');
buttons.appendChild(firstButton);
buttons.appendChild(previousButton);
buttons.appendChild(homeButton);
buttons.appendChild(nextButton);
buttons.appendChild(lastButton);

//Delete next button and last button if the pokemon is the last one
if (getId() == 905) {
   buttons.removeChild(nextButton);
   buttons.removeChild(lastButton);
}
//Delete previous button and first button if the pokemon is the first one
if (getId() == 1) {
   buttons.removeChild(previousButton);
   buttons.removeChild(firstButton);
}
document.body.appendChild(buttons);