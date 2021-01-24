package br.com.prog3.semanapratica2.model;

import java.io.Serializable;
import java.sql.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

import org.hibernate.annotations.Proxy;

@Entity
@Table(name = "dependente")
@Proxy(lazy = false)
public class Dependente implements Serializable {

    /**
     * Generated serialVersionUID
     */
    private static final long serialVersionUID = 1L;

    @ManyToOne
    @JoinColumn(name = "cpfEmpregado")
    private String cpfEmpregado;

    @Column(name = "nome")
    private String nome;

    @Column(name = "grauParentesco")
    private Integer grauParentesco;

    @Column(name = "dataNascimento")
    private Date dataNascimento;

    public Dependente() {
    }

    public Dependente(String cpfEmpregado, String nome, Integer grauParentesco, Date dataNascimento) {
        this.cpfEmpregado = cpfEmpregado;
        this.nome = nome;
        this.grauParentesco = grauParentesco;
        this.dataNascimento = dataNascimento;
    }

    public static long getSerialversionuid() {
        return serialVersionUID;
    }

    public String getCpfEmpregado() {
        return cpfEmpregado;
    }

    public void setCpfEmpregado(String cpfEmpregado) {
        this.cpfEmpregado = cpfEmpregado;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer getGrauParentesco() {
        return grauParentesco;
    }

    public void setGrauParentesco(Integer grauParentesco) {
        this.grauParentesco = grauParentesco;
    }

    public Date getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(Date dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

}
