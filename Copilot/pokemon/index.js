const pokemonContainer = document.querySelector(".pokemon-container");

//function to fetch the pokemon data with id
function fetchPokemon(id) {
   fetch(`https://pokeapi.co/api/v2/pokemon/${id}/`)
      .then((res) => res.json())
      .then((data) => {
         createPokemonCard(data);
      });
}

//function to fetch n pokemons after an offset
function fetchPokemons(limit, offset) {
   for (let i = offset; i < offset + limit; i++)  fetchPokemon(i);
}



//function to create a pokemon card
function createPokemonCard(pokemon) {

   const imgContainer = document.createElement('div');
   imgContainer.classList.add('img-container');
      
   const img = document.createElement('img');
   img.src = "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/versions/generation-v/black-white/animated/" + pokemon.id + ".gif";
   //if  src is not found, use the default image
   if (img.src = "null")
      img.src = pokemon.sprites.front_default;


   imgContainer.appendChild(img);


   imgContainer.addEventListener('click', () => {
      //go to pokemon.html
      window.location.href = `pokemon.html?id=${pokemon.id}`;
   }
   //add image to the card
   );
   pokemonContainer.appendChild(imgContainer);
   
}
fetchPokemons(10, 1);

//Create a button to fetch 1 more pokemons indicated by the user
const fetch1MorePokemon = document.createElement('button');
fetch1MorePokemon.textContent = "Fetch 1 more pokemon";
fetch1MorePokemon.addEventListener('click', () => {
   fetchPokemons(1, pokemonContainer.childElementCount + 1);

}
);

//Create a button to fetch 10 more pokemon indicated by the user
const fetch10MorePokemon = document.createElement('button');
fetch10MorePokemon.textContent = "Fetch 10 more pokemons";
fetch10MorePokemon.addEventListener('click', () => {
   fetchPokemons(10, pokemonContainer.childElementCount + 1);
}
);


//Create a button to fetch 100 next pokemon indicated by the user
const fetch100MorePokemon = document.createElement('button');
fetch100MorePokemon.textContent = "Fetch 100 more pokemons";
fetch100MorePokemon.addEventListener('click', () => {
   fetchPokemons(100, pokemonContainer.childElementCount + 1);
}
);


//Create a button to fetch all the remaining pokemon
const fetchAllRemainingPokemon = document.createElement('button');
fetchAllRemainingPokemon.textContent = "Fetch all remaining pokemons";
fetchAllRemainingPokemon.addEventListener('click', () => {
   fetchPokemons(905 - pokemonContainer.childElementCount+1, pokemonContainer.childElementCount+1);
}
);

//Create a button to delete all pokemons but left the first one
const deleteAllPokemon = document.createElement('button');
deleteAllPokemon.textContent = "Clear pokemons";
deleteAllPokemon.addEventListener('click', () => {
   pokemonContainer.innerHTML = "";
   fetchPokemons(1, 1);
}
);
//Move the buttons to the bottom of the page
document.body.appendChild(fetch1MorePokemon);
document.body.appendChild(fetch10MorePokemon);
document.body.appendChild(fetch100MorePokemon);
document.body.appendChild(fetchAllRemainingPokemon);
document.body.appendChild(deleteAllPokemon);

