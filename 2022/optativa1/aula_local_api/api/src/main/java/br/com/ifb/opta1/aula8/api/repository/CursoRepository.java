package br.com.ifb.opta1.aula8.api.repository;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import br.com.ifb.opta1.aula8.api.domain.Curso;

@Repository
public interface CursoRepository extends CrudRepository<Curso, Long>{
}
