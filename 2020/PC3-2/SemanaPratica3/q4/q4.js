//
btn.addEventListener("click", () => {
    var report = document.getElementById("report");
    var statistcs = document.getElementById("details");
    var alunos = [];
    var aprovados = 0;
    var reprovados = 0;

    // Adicionando os dados para os 20 alunos
    for (let i = 0; i < 20; i++) {

        var aluno = {
            nr: i,
            nota: Math.floor(Math.random() * 100),
        };

        aluno.status = aluno.nota > 50 ? "APROVADO" : "REPROVADO";

        alunos.push(aluno);
    }

    for (let i = 0; i < 20; i++) {


        var row = report.insertRow(2);

        var nr = row.insertCell(0);
        nr.innerHTML = `${alunos[ i ].nr}`;

        var nota = row.insertCell(1);
        nota.innerHTML = `${alunos[ i ].nota}`;

        var status = row.insertCell(2);
        status.innerHTML = `${alunos[ i ].status}`;
    }

    for (let i = 0; i < 20; i++) {
        if (alunos[ i ].status === "APROVADO") {
            aprovados++;
        } else {
            reprovados++;
        }

    }

    statistcs.innerHTML = "";
    statistcs.insertAdjacentHTML("beforeend", `APROVADOS: ${aprovados} (${(aprovados * 10) / 2}%)   REPROVADOS: ${reprovados} (${(reprovados * 10) / 2}%)`);

});

