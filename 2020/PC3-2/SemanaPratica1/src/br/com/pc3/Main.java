package br.com.pc3;

import java.lang.annotation.ElementType;
import java.lang.annotation.Target;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // 1) Escreva um programa em Java que crie um ArrayList adicione
        //algumas cores (string) e as imprima na tela.
        List<String> cores = new ArrayList();

        cores.add("Amarelo");
        cores.add("Verde");
        cores.add("Magenta");
        cores.add("Cinza");
        cores.add("Marrom");
        cores.add("Azul");
        cores.add("Branco");
        cores.add("Roxo");

        for (String color : cores) {
            System.out.println("<" + color + ">");
        }

//        2) Usando o ArrayList do exercício 1, faça as seguintes operações:
//        a) adicione um elemento na primeira posição da lista;
        cores.add(0, "Turquesa");

//        b) remova o terceiro elemento da lista;
        cores.remove(2);

//        c) copie o ArrayList para outro;
        List<String> cores2 = new ArrayList<>();
        cores2.addAll(cores);

//        d) ordene o ArrayList de cores pelo nome
        Collections.sort(cores);

//        3) Escreva um programa para criar um HashMap de String, use um
//        Integer com chave. Adicione 20 elementos aleatórios no HashMap.
//        Liste as chaves e os valores do HashMap.
        Map<Integer, String> elementos = new HashMap<>();

        for (int i = 0; i < 20; i++){
            elementos.put(i + 1, "Elemento " +  (i + 1));
        }

        for(Map.Entry<Integer, String> entry : elementos.entrySet()){
            System.out.println("{ " + entry.getKey() + " : " + entry.getValue() + " }");
        }

//        4) Qual é a diferença fundamental entre a classe Vector e a classe
//        ArrayList do pacote java.util?
//        R: * O Vector é Thread-Safe, e o ArrayList não. isso significa que se
//        queremos precisamos que a aplicação seja Thread-Safe em algum ponto,
//        o Vector garante isso.
//
//        * A alocação dinâmica na classe Vector é diferente do ArrayList. Enquanto
//        o ArrayList aumenta 50% do seu tamanho quando a lista está cheia, o Vector
//        aumenta o dobro disso, ou seja, uma lista cheia com 10 elementos ficará com
//        tamanho total de 20, com 10 posições vazias.

//        5) Qual é a diferença fundamental entre a classe Hashtable e a classe
//        HashMap do pacote java.util?
//        R: A primeira diferença é que o HashTable é Thread-Safe, já o HashMap não,
//        ou seja o HashMap é mais eficiente em cenários que não requerem comportamento
//        thread-safe.
//        Outras diferenças são:
//        Hashtable: {é mais rápida, aceita valores nulos e uma chave nula, consome menos memória,
//        mais moderna.
//        }
//
//        Hashmap: {Não aceita nulos, iterar é mais trabalhoso, possui o método contains(), ocupa
//        mais memória, considerada obsoleta, tem overhead pela sincronização}

//        6) Crie uma classe chamada Reflexao e crie, dentro dela, dois
//        métodos, um para mostrar os atributos de uma classe, que será
//        recebida pelo nome como parâmetro e outro para mostrar os
//        métodos dessa classe. Crie uma classe chamada Teste, com o
//        método main, e use a classe Reflexao para mostrar os métodos e os
//        atributos da classe mostrada a seguir. Dica: use a ativdade 4 da
//        aula 3 como base.
        System.out.println("\n\nQuestão 6");
        Pessoa p = new Pessoa("Ana Maria", 23, "05547899963", "5447823");
        Reflexao.atributos(p);
        Reflexao.metodos(p);

//        7) Crie uma annotation chamada AnnotationEndereco, que tenha os
//        seguintes elementos: logradouro, numero, bairro, cidade e estado.
//        Use default “S/N” para número, caso o valor não seja passado. Mostre
//        um exemplo de uso dessa annotation. Dica: use como base o item
//        “4. Criando Annotations” da aula 4.

        // Exemplo de uso conforme pedido na quetão 7
        @MinhaAnotation(
                logradouro = "Teste",
                bairro = "Bairro teste",
                cidade = "Cidade teste",
                estado = "Estado teste"
        )
        class MinhaClasse{
        }


    }
}

// Para a questão 6
class Reflexao{

    public static void atributos(Object objeto) {
        Class<?> classe = objeto.getClass();
        Field[] campos = classe.getDeclaredFields();

        String atributo = "";
        Object valorAtributo = null;

        for(Field campo : campos){
            try {

                atributo = campo.getName();
                campo.setAccessible(true); // Necessário por causa do encapsulamento

                valorAtributo = campo.get(objeto);

            }catch (Exception e){
                e.printStackTrace();
            }
            System.out.println("{" + atributo + " : " + valorAtributo + "}");
        }
    }

    public static void metodos(Object objeto) {
        Class<?> classe = objeto.getClass();
        Method[] campos = classe.getDeclaredMethods();

        String metodo = "";

        for(Method innetMetodo : campos){
            try {

                metodo = innetMetodo.getName();
                innetMetodo.setAccessible(true); // Necessário por causa do encapsulamento


            }catch (Exception e){
                e.printStackTrace();
            }
            System.out.println("{" + metodo + "}");
        }
    }

}

//Para a questão 6
class Pessoa {
    private String nome;
    private int idade;
    private String cpf;
    private String rg;
    public Pessoa(String nome, int idade, String cpf, String rg){
        this.nome = nome;
        this.idade = idade;
        this.cpf = cpf;
        this.rg = rg;
    }
    public String getNome() {
        return nome;
    }
    public int getIdade() {
        return idade;
    }
    public String getCpf() {
        return cpf;
    }
    public String getRg() {
        return rg;
    }
}

// Para a quetão 7
@Target({ElementType.TYPE_USE})
@interface MinhaAnotation{
    String logradouro() default "";
    String numero() default "S/N";
    String bairro() default "";
    String cidade() default "";
    String estado() default "";

}