package br.com.ifb.opta1.aula8.api.enums;

public enum ModalidadeEnum {

PRESENCIAL("Presencial"),
EAD("Ensino a distância"),
SEMI_PRESENCIAL("Semi presencial");

private String descricao;

private ModalidadeEnum(String descricao) {
    this.descricao = descricao;
}

public String getDescricao() {
    return descricao;
}
    
}
