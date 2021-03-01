

var btn = document.getElementById("btn");
var fieldA = document.getElementById("field-a");

//
btn.addEventListener("click", () => {

    if (!fieldA.value == 0 || !fieldA.value == '' || !fieldB.value == 0 || !fieldB.value == '') {
        checaMinimoMenorQueMaximo(fieldA, fieldB);
        checaNumerosEntreMinimoEMaximo(fieldA, fieldB);
    }
});


// Checa se o valor minimo é menor que o máximo, senão,
// zera os campos, e mostra uma mensagem
function checaMinimoMenorQueMaximo(min, max) {

    if (min.value > max.value) {
        console.log("min: ", min.value, "max, ", max);
        min.value = 0;
        max.value = 0;

        alert("O valor minimo é maior que o valor máximo")
    }
}

function checaNumerosEntreMinimoEMaximo(min, max) {
    let qtde = 0;
    for (let i = min.value; i < max.value - 1; i++) {
        if (i % 2 == 0) {
            if (i % 3 == 0) {
                qtde++;
            }
        }
    }
    console.log("Múltiplos de 2 e 3 entre o minimo e máximo: ", qtde);
}
