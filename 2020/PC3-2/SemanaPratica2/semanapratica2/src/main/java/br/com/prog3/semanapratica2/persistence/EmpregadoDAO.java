package br.com.prog3.semanapratica2.persistence;

import java.util.List;

import br.com.prog3.semanapratica2.model.Empregado;

public interface EmpregadoDAO {

    public void incluir(Empregado empregado);

    public void alterar(Empregado empregado);

    public void excluir(Empregado empregado);

    public List<Empregado> listarTodos();

    public Empregado buscarPeloCpf(String cpf);

}
