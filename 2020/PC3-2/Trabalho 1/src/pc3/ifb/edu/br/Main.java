package pc3.ifb.edu.br;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.util.*;

public class Main {

    // Para a questão 1
    static List l1 = new ArrayList<>();

    public static void main(String[] args) {

        // 1. Implemente uma classe que possua um ArrayList e insira 200 Strings nesta lista
        for (int i = 0; i < 200; i++) {
            Main.l1.add("String " + i + 1);
        }

        //2. Faça um ArrayList e insira as Strings “String 1”, “String 2” e “String 3” cada uma duas vezes, percorra
        // todos os elementos e imprima (System.out.println()). Observe o resultado. Quantos elementos têm a coleção?
        List l2 = new ArrayList<>();
        l2.add("String 1");
        l2.add("String 1");
        l2.add("String 2");
        l2.add("String 2");
        l2.add("String 3");
        l2.add("String 3");

        l2.forEach(element -> {
            System.out.println(element);
        });

//        3. Utilizando a classe Collections desordene a coleção criada no exercício 2. Imprima (System.out.println()) o
//        resultado
        Collections.shuffle(l2);
        System.out.println(l2);

//        4. Utilizando a classe Collections pesquise por “String 2” na coleção criada no exercício 2. Imprima
//        (System.out.println()) o resultado.
        System.out.println("Q4: " + l2.indexOf("String 2"));

//        5. Utilizando a classe Collections ordene a coleção criada no exercício 2. Imprima (System.out.println()) o
//        resultado.
        Collections.sort(l2);
        System.out.println(l2);

//        6. Crie uma classe chamada Servico que tenha os seguintes atributos: codigo, descricao, precoHora, qtdeHora.
//        Deve-se criar um método que calcule o valor do serviço da seguinte forma: valor = precoHora*qtdHora. O preço
//        da hora de serviço deve ser atribuído no momento da criação do objeto da classe. Sobrescreva o método
//        compareTo para fazer a ordenação pela descricao. Crie, também, uma classe usuária de Servico que leia vários
//        serviços, até o usuário decida parar de digitar, e guarde-os em uma coleção e no final imprima a lista na
//        ordem que foi digitada e na ordem alfabética da Descrição.
        ServiceController c = new ServiceController();
        //c.run();

//        7. Faça um HashSet e insira as Strings “String 1”, “String 2” e “String 3” cada uma duas vezes, percorra todos os
//        elementos e imprima (System.out.println()). Observe o resultado. Quantos elementos têm a coleção?
        Set s1 = new HashSet();
        s1.add("String 1");
        s1.add("String 1");
        s1.add("String 2");
        s1.add("String 2");
        s1.add("String 3");
        s1.add("String 3");
        System.out.println("Q7\n" + s1);

//        8. Faça um HashMap e insira as Strings “String 1”, “String 2” e “String 3” cada uma duas vezes, utilize o
//        numeral como chave, percorra todos os elementos e imprima (System.out.println()). Observe o resultado.
//        Quantos elementos têm a coleção?
        Map m1 = new HashMap<Integer, String>();
        m1.put(1, "String 1");
        m1.put(1, "String 1");
        m1.put(2, "String 2");
        m1.put(2, "String 2");
        m1.put(3, "String 3");
        m1.put(3, "String 3");

        m1.forEach((key, element) -> {
            System.out.println(element);
        });

        System.out.println("O map m1 possui " + m1.size() + " elementos");

//        9. Adicione os números 100, 20, 200, 30, 80, 40, 100, 200 a um List, percorra todos os elementos utilizando
//        for- enhanced (for-each) e calcule a média
        List l4 = new ArrayList();
        l4.add(100);
        l4.add(20);
        l4.add(200);
        l4.add(30);
        l4.add(80);
        l4.add(40);
        l4.add(100);
        l4.add(200);

        l4.forEach(element -> System.out.println(element));

//        10. Adicione os números 100, 20, 200, 30, 80, 40, 100, 200 a um List, percorra todos os elementos utilizando
//        um Iterator e calcule a média.
        int soma = l4.stream().mapToInt(element -> (int) element).sum();
        soma = soma / l4.size();

//        11. Adicione os números 100, 20, 200, 30, 80, 40, 100, 200 a um Set, percorra todos os elementos utilizando
//        for- enhanced (for-each) e calcule a média.
        Set s2 = new HashSet();
        s2.add(100);
        s2.add(20);
        s2.add(200);
        s2.add(30);
        s2.add(80);
        s2.add(40);
        s2.add(100);
        s2.add(200);

        int media = 0;
        for (Object valor : s2) {
            media += (int) valor;
        }

        media = media / s1.size();

//        12. Porque as médias encontradas nos exercícios 10 e 11 ficaram diferentes?
//        R: Porque no exercício usamos uma implementação de coleção que permite elementos duplicados permanecerem
//        mutuamente, influenciado assim o valor da final, já na questão 11, usamos um contêiner de coleção que não
//        Admite valores duplicados, sendo assim, quando o elemento já existia na lista, ele simplesmente ignora a
//        adição do mesmo.

//        13. Crie uma classe Aluno com os atributos Nome , RG e data de nascimento. Sobrescreva o método equals() de
//        forma que dois alunos sejam considerados iguais apenas se possuírem o mesmo RG.
        Aluno a = new Aluno();

//        14. Compare o desempenho das coleções HashMap e HashSet. Insira nas duas coleções um total de 20.000
//        alunos (da classe do exercício anterior) e pesquise por um deles, compare o tempo de pesquisa em cada uma
//        das coleções.

//        15. Implemente uma classe ContaCorrente com os atributos Agencia, Numero, Nome, CPF e Saldo. Sobrescreva
//        os métodos equals() de forma que duas contas correntes sejam consideradas iguais apenas se possuírem o
//        mesmo Numero, e sobrescreva o método hashCode().

//        16. Crie um HashSet e adicione 5 (cinco) ContaCorrente diferentes. Imprima o resultado (System.out.println()).
        Set contas = new HashSet<ContaCorrente>();
        contas.add(new ContaCorrente(0001, 123, "Ana", "12345678911", 5000.0));
        contas.add(new ContaCorrente(0001, 456, "Paulo", "12345675511", 2500.0));
        contas.add(new ContaCorrente(0001, 789, "Maria", "12345778911", 4000.0));
        contas.add(new ContaCorrente(0001, 012, "Marcos", "12345666911", 5400.0));
        contas.add(new ContaCorrente(0001, 034, "Bernardo", "12341178911", 2300.0));
        contas.add(new ContaCorrente(0001, 056, "Marina", "12345633911", 7800.0));

//        17. Qual interface do Framework Collections você utilizaria para representar uma Turma de faculdade,
//        considerando que cada aluno está matriculado apenas uma vez?
//        R: Eu utilizaria o HashSet abarcando objetos Aluno contendo todos atributos que os compõem porque, dessa
//        maneira, eu poderia implementar o método equals apontando para alguma informação única a cada aluno (RG, CPF,
//        Matrícula etc). isso faria com que o Hashset considerasse o(s) atributo(s) apontado(s) para adicionar ou não
//        o objeto na lista.

//        18. Implemente código com a estrutura de dados definida no exercício anterior, adicione alguns alunos com o
//        mesmo RG, utilize a classe Aluno do exercício 18. Percorra todos os elementos, observe o resultado. Existem
//        alunos nesta turma com o mesmo código?
        Set alunos = new HashSet<Aluno>();

        alunos.add(new Aluno("Ana", "555", "04/08/2001"));
        alunos.add(new Aluno("Carlos", "777", "04/08/2001"));
        alunos.add(new Aluno("Mariana", "888", "04/08/2001"));
        alunos.add(new Aluno("Bernardo", "333", "04/08/2001"));
        alunos.add(new Aluno("Márcio", "555", "04/08/2001")); // Esse aqui não vai entrar

        System.out.println("Alunos\n" + alunos);

//        19. Sobrescreva o método hashCode da classe Aluno, desenvolvida no exercício 13, observando a
//        implementação do método equals ().


    }
}


//Para a questão 6
class Servico implements Comparable {
    String codigo, descricao;
    Double precoHora, valorServico;
    Integer qtdeHora;

    public Servico(String codigo, String descricao, Double precoHora, Integer qtdeHora) {
        this.codigo = codigo;
        this.descricao = descricao;
        this.precoHora = precoHora;
        this.qtdeHora = qtdeHora;

        calculaValorServico();
    }


    private void calculaValorServico() {
        this.valorServico = this.precoHora * this.qtdeHora;
    }

    @Override
    public int compareTo(Object o) {
        return this.descricao.compareTo(((Servico) o).descricao);
    }

    @Override
    public String toString() {
        return "Servico{" +
                "codigo='" + codigo + '\'' +
                ", descricao='" + descricao + '\'' +
                ", precoHora=" + precoHora +
                ", VALOR_SERVICO=" + valorServico +
                ", qtdeHora=" + qtdeHora +
                '}';
    }
}

// Para a questão 6
class ServiceController {
    List l3 = new ArrayList<>();
    private Integer continuar = 1;

    public void run() {

        do {

            String descricao;
            double precoPorHora;
            int qtdeHora;

            System.out.print("Descrição:   ");
            descricao = new Scanner(System.in).nextLine();

            System.out.print("Preço/hora:   ");
            precoPorHora = new Scanner(System.in).nextDouble();

            System.out.print("Qtde/hora:   ");
            qtdeHora = new Scanner(System.in).nextInt();

            novoServico(new Servico(String.valueOf(l3.size() + 1), descricao, precoPorHora, qtdeHora));

            System.out.print("Adicionar mais um? (1 = sim, 0 = não)   ");
            continuar = new Scanner(System.in).nextInt();

        } while (continuar != 0);

        System.out.println(l3);


    }


    public void novoServico(Servico s) {
        l3.add(s);
    }
}


//Para a quetão 13
class Aluno {
    String nome;
    String rg;
    String dataNascimento;

    public Aluno() {

    }

    public Aluno(String nome, String rg, String dataNascimento) {
        this.nome = nome;
        this.rg = rg;
        this.dataNascimento = dataNascimento;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Aluno aluno = (Aluno) o;
        return Objects.equals(rg, aluno.rg);
    }

    @Override
    public int hashCode() {
        return Objects.hash(rg);
    }

    @Override
    public String toString() {
        return "\nnome = " + nome + "   rg = " + rg;
    }
}

class ContaCorrente {
    Integer agencia;
    Integer numero;
    String nome;
    String cpf;
    Double saldo;

    public ContaCorrente() {

    }

    public ContaCorrente(Integer agencia, Integer numero, String nome, String cpf, Double saldo) {
        this.agencia = agencia;
        this.numero = numero;
        this.nome = nome;
        this.cpf = cpf;
        this.saldo = saldo;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ContaCorrente that = (ContaCorrente) o;
        return Objects.equals(numero, that.numero);
    }

    @Override
    public int hashCode() {
        return Objects.hash(numero);
    }
}