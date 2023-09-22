const getPokemons = fetch("https://pokeapi.co/api/v2/pokemon?limit=0&offset=0").then(r => r.json()).then(data => {
  return data;
});

const getImagePokemon = (pokemonUrl) => fetch(pokemonUrl).then(r=>r.json()).then(data => {
  return data.sprites.front_default;
});

const getPokemonId = (pokemonUrl) => fetch(pokemonUrl).then(r => r.json()).then(data => {
   return data.id;
});

const getPokemonsImages = async (pokemons) => {
  for(let i=0; i<pokemons.length; i++) {
   pokemons[i].image = await getImagePokemon(pokemons[i].url);
   pokemons[i].id = await getPokemonId(pokemons[i].url);
}
  return pokemons;
}

window.onload = async () => {
  let data = await getPokemons;
  let pokemons = await getPokemonsImages(data.results);
   for (let i = 0; i < pokemons.length; i++) {
      let container = document.createElement("div");
      container.className = "col text-center card";

      let link = document.createElement("a");
      link.className = "btnLink";

      link.id = pokemons[i].id;

      let h2Container = document.createElement("h2");
      h2Container.innerText = pokemons[i].name;

      let imgContainer = document.createElement("img");
      imgContainer.src = pokemons[i].image;
      imgContainer.className = "pokemon-image";
      
      link.appendChild(imgContainer);
      link.appendChild(h2Container);
      container.appendChild(link);
   
      document.getElementById("pokemons").appendChild(container);
   }
   const pokeList = document.querySelectorAll(".card");
   pokeList.forEach((list, index) => {
      const btn = list.querySelector(".btnLink");
      btn.addEventListener("click", () => {
         btn.setAttribute("href", "poke.html" + "?id=" + btn.id);

      });
   });
};