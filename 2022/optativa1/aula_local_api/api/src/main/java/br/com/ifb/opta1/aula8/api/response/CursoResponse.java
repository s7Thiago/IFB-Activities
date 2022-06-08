package br.com.ifb.opta1.aula8.api.response;

import br.com.ifb.opta1.aula8.api.enums.ModalidadeEnum;
import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class CursoResponse {
    private Long id;
    private String nome;
    private Integer cargaHoraria;
    private ModalidadeEnum modalidade;
}
