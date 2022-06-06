package br.com.ifb.opta1.aula8.api.resources;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.com.ifb.opta1.aula8.api.domain.Curso;
import br.com.ifb.opta1.aula8.api.enums.ModalidadeEnum;
import br.com.ifb.opta1.aula8.api.service.CursoService;

@RestController
@RequestMapping("/api/v1/cursos")
public class CursoResource {

    @Autowired
    private CursoService cursoService;

    @PostMapping
    public Curso save(@RequestBody Curso curso) {
        return cursoService.save(curso);
    }

    @GetMapping
    public ResponseEntity<List<Curso>> findAll() {
        List<Curso> cursos = cursoService.findAll();
        if (cursos == null || cursos.isEmpty()) {
            return new ResponseEntity<List<Curso>>(HttpStatus.NO_CONTENT);
        }
        return new ResponseEntity<List<Curso>>(cursos, HttpStatus.OK);
    }

    @GetMapping(path = { "/{id}" })
    public ResponseEntity<?> findById(@PathVariable Long id) {
        return cursoService.findById(id)
                .map(record -> ResponseEntity.ok().body(record))
                .orElse(ResponseEntity.notFound().build());
    }

    @PutMapping(value = "/{id}")
    public ResponseEntity<Curso> update(
            @PathVariable("id") Long id,
            @RequestBody Curso curso) {

        return cursoService.findById(id)
                .map(record -> {
                    record.setCargaHoraria(curso.getCargaHoraria());
                    record.setNome(curso.getNome());
                    record.setModalidade(curso.getModalidade());

                    Curso updated = cursoService.save(record);

                    return ResponseEntity.ok().body(updated);

                }).orElse(ResponseEntity.notFound().build());
    }

    @GetMapping(path = { "modalidade/{modalidade}" })
    public ResponseEntity<?> findByModalidade(@PathVariable("modalidade") ModalidadeEnum modalidade) {
        List<Curso> cursos = cursoService.findByModalidade(modalidade);
        return cursos.isEmpty() ? ResponseEntity.noContent().build() : ResponseEntity.ok(cursos);
    }

}