var btn = document.getElementById("btn-calcular");
var fieldQtde = document.getElementById("field-1");
var fieldValorMin = document.getElementById("field-2");
var fieldValorMax = document.getElementById("field-3");

//
btn.addEventListener("click", () => {
    var collection = [];


    //colocando os valores minimo e maximo em posições aleatórias
    collection[ Math.floor(Math.random() * fieldQtde.value + 1) ] = fieldValorMin.value;
    collection[ Math.floor(Math.random() * fieldQtde.value + 1) ] = fieldValorMax.value;


    fillArray(collection, fieldQtde.value, fieldValorMax.value, fieldValorMin);

    console.log("teste: ", collection);

});


function fillArray(collection, qtde, max, min) {
    // Preenchendo as demais posições com fieldQtde.value números que não existam no array
    do {

        let pushTarget = getRandomInt(min, max);

        if (collection.includes(pushTarget)) {
            collection.push(pushTarget);
        } else {
            let pushTarget = getRandomInt(min, max);
            collection.push(pushTarget);

        }

    } while (!isEmptyIndex(collection));

}

// Verifica se existe posição vazia no array
function isEmptyIndex(array) {
    for (let i = 0; i < array.length; i++) {
        if (typeof array[ i ] === "undefined") {
            return true;
        }

    }

    return false;
}

function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
