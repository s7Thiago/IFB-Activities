package br.com.prog3.semanapratica2.model;

import java.io.Serializable;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.annotations.Proxy;

@Entity
@Table(name = "empregado")
@Proxy(lazy = false)
public class Empregado implements Serializable {

    /**
     * Generated serialVersionUID
     */
    private static final long serialVersionUID = 1L;

    @Id
    @Column(name = "cpf")
    private String cpf;

    @Column(name = "nome")
    private String nome;

    @Column(name = "idade")
    private Integer idade;

    @Column(name = "salario")
    private Double salario;

    @OneToMany(mappedBy = "empregado", targetEntity = Dependente.class, cascade = CascadeType.ALL, fetch = FetchType.EAGER)
    List<Dependente> dependentes;

    public Empregado() {
    }

    public Empregado(String cpf, String nome, Integer idade, Double salario) {
        this.cpf = cpf;
        this.nome = nome;
        this.idade = idade;
        this.salario = salario;
    }

    public static long getSerialversionuid() {
        return serialVersionUID;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer getIdade() {
        return idade;
    }

    public void setIdade(Integer idade) {
        this.idade = idade;
    }

    public Double getSalario() {
        return salario;
    }

    public void setSalario(Double salario) {
        this.salario = salario;
    }

}
