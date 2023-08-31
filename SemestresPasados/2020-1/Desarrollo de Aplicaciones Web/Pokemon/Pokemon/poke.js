const queryString = window.location.search;
const urlparams = new URLSearchParams(queryString);
let id = urlparams.get(`id`);
console.log(id);
const getPokemon = fetch(`https://pokeapi.co/api/v2/pokemon/` + id).then(r => r.json()).then(data => {
  return data;
});

window.onload = async () => {
   let pokemon = await getPokemon;
   let j = 0;
   let container = document.createElement("div");
   container.className = "col text-center card";
  
   let h2Container = document.createElement("h2");
   h2Container.innerText = pokemon.name;
   
   
   let imgContainer = document.createElement("img");
   imgContainer.src = pokemon.sprites.front_default;
   imgContainer.className = "pokemon-image";

   let abilityContainer = document.createElement("Abilities");
   abilityContainer.innerText = "  ABILITIES: "
   for (j = 0; j < pokemon.abilities.length - 1; j++) {
      abilityContainer.innerText += pokemon.abilities[j].ability.name + ", ";
   }
   abilityContainer.innerText += pokemon.abilities[j].ability.name + ".\n";
   
   let typeContainer = document.createElement("Type");
   typeContainer.innerText = "  TYPE(S): "
   for (j = 0; j < pokemon.types.length - 1; j++) {
      typeContainer.innerText += pokemon.types[j].type.name + ", ";
   }
   typeContainer.innerText += pokemon.types[j].type.name + ".\n";
      
   let sizeContainer = document.createElement("Size");
   sizeContainer.innerText = "HEIGHT: " + pokemon.height/10 + "m." + " WEIGHT: " + pokemon.weight/10 + "kg.";
         
   container.appendChild(imgContainer);
   container.appendChild(h2Container);
   container.appendChild(abilityContainer);
   container.appendChild(typeContainer);
   container.appendChild(sizeContainer);

   document.getElementById("pokemon").appendChild(container);
};