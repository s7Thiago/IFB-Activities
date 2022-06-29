package br.com.ifb.opta1.aula8.api.repository;

import java.util.List;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import br.com.ifb.opta1.aula8.api.domain.Curso;
import br.com.ifb.opta1.aula8.api.enums.ModalidadeEnum;

@Repository
public interface CursoRepository extends CrudRepository<Curso, Long>{
    List<Curso> findByModalidade(ModalidadeEnum modalidade);
}
