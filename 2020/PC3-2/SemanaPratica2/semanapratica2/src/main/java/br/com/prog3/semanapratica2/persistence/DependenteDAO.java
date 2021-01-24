package br.com.prog3.semanapratica2.persistence;

import java.util.List;

import br.com.prog3.semanapratica2.model.Dependente;

public interface DependenteDAO {
    public void incluir(Dependente dependente);

    public void alterar(Dependente dependente);

    public void excluir(Dependente dependente);

    public List<Dependente> listarTodos();

}
