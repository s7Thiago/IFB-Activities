
var btn = document.getElementById("btn");
var fieldA = document.getElementById("field-a");
var resultado = document.getElementById("resultado");

//
btn.addEventListener("click", () => {

    var timeA = Date.now();

    var executionTime = Date.now() - timeA;

    document.write(`${fieldA.value}! =  ${fact(fieldA.value)} (${executionTime} milissegundos)`)

});

function fact(value) {
    var resultado = 1;

    while (value > 1) {
        resultado *= value;
        value--;
    }

    return resultado;

}

