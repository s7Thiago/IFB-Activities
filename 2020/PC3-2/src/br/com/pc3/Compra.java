package br.com.pc3;

public class Compra extends Thread {

    private Produto produto;
    private int quantidade;
    private static final int REPETICOES = 10;
    private static final int ESPERA = 10;

    public Compra(Produto produto, int quantidade) {
        this.produto = produto;
        this.quantidade = quantidade;
    }

    public void run() {
        try {
            for (int i = 1; i <= REPETICOES && !isInterrupted(); i++) {
                produto.adicionar(quantidade);
                sleep(ESPERA);
            }
        } catch (InterruptedException ie) {
            System.out.println(ie.getMessage());
        }
    }
}