var ladoA = document.getElementById("lado-a");
var ladoB = document.getElementById("lado-b");
var ladoC = document.getElementById("lado-c");

var txtResultado = document.getElementById("resultado");

var btnCalc = document.getElementById("btn-calcular");

//
btnCalc.addEventListener("click", () => {

    if (ladoA.value == ladoB.value && ladoB.value == ladoC.value) {
        txtResultado.innerHTML = "Equilátero";
    } else if (ladoA.value == ladoB.value && ladoB.value != ladoC.value) {
        txtResultado.innerHTML = "Isósceles";
    } else if (ladoA.value != ladoB.value && ladoB.value != ladoC.value) {
        txtResultado.innerHTML = "Escaleno";

    }


});
