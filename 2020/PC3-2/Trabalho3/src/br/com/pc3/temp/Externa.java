package br.com.pc3.temp;

public class Externa {

    // Inner class
    class Interna {
    }
}

class Main {
    public static void main(String[] args) {

        // Passo 1: estanciar a classe externa
        Externa externa = new Externa();

        // Passo 2: Utilizar a estância da classe externa para estanciar a interna
        Externa.Interna interna = externa.new Interna();

        // Ou, também é possível simplesmente:
        Externa.Interna interna2 = new Externa().new Interna();

    }
}
