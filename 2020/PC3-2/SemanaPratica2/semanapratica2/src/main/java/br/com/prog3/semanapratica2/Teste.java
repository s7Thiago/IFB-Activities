package br.com.prog3.semanapratica2;

import java.sql.Date;
import java.util.List;

import br.com.prog3.semanapratica2.controller.DependenteController;
import br.com.prog3.semanapratica2.controller.EmpregadoController;
import br.com.prog3.semanapratica2.model.Dependente;
import br.com.prog3.semanapratica2.model.Empregado;

public class Teste {
    public static void main(String[] args) {
        System.out.println("\n\nHello World\n\n");

        // Inserindo um novo empregado
        Empregado empregado = new Empregado("054.578.458-77", "Bernardo Santos", 26, 14000.00);
        EmpregadoController empregadoController = new EmpregadoController();

        empregadoController.incluir(empregado);

        // Atualizando o empregado
        empregado = new Empregado("054.578.458-77", "Bernardo Santos", 27, 17000.00);
        empregadoController.alterar(empregado);

        // Excluindo empregado
        empregadoController.excluir(empregado);

        // Listando todos os empregados
        List<Empregado> empregados = empregadoController.listarTodos();

        empregados.forEach(emp -> System.out
                .println("*************\nNome: " + emp.getNome() + "\nCPF: " + emp.getCpf() + "*************"));

        // Buscando empregado pelo cpf
        empregado = empregadoController.buscarPeloCpf("054.578.458-77");

        // **************************************************

        // Incluindo dependentes
        DependenteController dependenteController = new DependenteController();
        Dependente dependente = new Dependente(empregado.getCpf(), "Francisco Alberto", 1, new Date(1997, 4, 4));

        dependenteController.incluir(dependente);

        // Atualizando dependente
        dependente = new Dependente(empregado.getCpf(), "Francisco Alberto da Silva", 1, new Date(1997, 4, 4));
        dependenteController.alterar(dependente);

        // Excluindo dependente
        dependenteController.excluir(dependente);

        // Listando todos os dependentes
        List<Dependente> dependentes = dependenteController.listarTodos();

        dependentes.forEach(emp -> System.out.println(
                "*************\nNome: " + emp.getNome() + "\nCPF: " + emp.getCpfEmpregado() + "*************"));

    }

}