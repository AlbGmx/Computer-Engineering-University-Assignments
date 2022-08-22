

var nombre = "Emmanuel Gomez";
var altura = 165;

var concatenacion = nombre + " " + altura;
/*
var datos = document.getElementById("datos");
datos.innerHTML = `
   <h1>Soy la caja de datos</h1>
   <h2>Mi nombre es ${nombre}</h2>
   <h3>Mido: ${altura} cm</h3>
`;  

if (altura >= 1.90) {
   datos.innerHTML += `<h1> Eres una persona Alta<h/1>`;
} else {
   datos.innerHTML += `<h1> Eres una persona bajita</h1>`;
}

for (var i = 0; i <= 2022; i++){
   //bloque de instrucciones
   datos.innerHTML += "<h2> Estamos en el año: " + i;
}
*/
function MuestraMiNombre(nombre, altura) {
   var Misdatos = `
      <h1>Soy la caja de datos</h1>
      <h2>Mi nombre es ${nombre}</h2>
      <h3>Mido: ${altura} cm</h3>
   `;  
   return Misdatos;
}

function imprimir() {
   var datos = document.getElementById("datos");
   datos.innerHTML = MuestraMiNombre("Emmanuel Gomez", 165)
}

imprimir();

var nombres = ['Emmanuel', 'Alberto', 'Gomez', 'Cardenas'];

document.write('<h1>Listado de nombres</h1>');
/*
for (i = 0; i < nombres.length; i++) {
   document.write(nombres[i] + '<br/>');
   
}
*/
nombres.forEach((nombre) => {
   document.write(nombre + '<br/>');
});