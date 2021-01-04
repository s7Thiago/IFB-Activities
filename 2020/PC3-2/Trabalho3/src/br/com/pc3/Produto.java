package br.com.pc3;

public class Produto {
    private String name;
    private Integer estoque;

    public Produto(){
        estoque = 0;
    }

    public int getEstoque(){
        return this.estoque;
    }

    public synchronized void adicionar(int quantidade) {
        System.out.println("Adicionando " + quantidade + " produtos...\n");
        this.estoque = estoque + quantidade; // Atualizado o estoque atual do produto
        System.out.println("(Add) Estoque atualizado: " + this.estoque + " itens.\n");
        notifyAll();
    }

    public  synchronized void retirar(int quantidade) throws InterruptedException{
        while (estoque < quantidade) {
            System.out.println("Retirada barrada");
            wait();
        }
        System.out.println("Retirando " + quantidade + " itens...");
        this.estoque -= quantidade; // Atualizando o estoque
        System.out.println("(Retirada) Estoque atualizado: " + this.estoque + " itens.\n");
        notifyAll();
    }
}
