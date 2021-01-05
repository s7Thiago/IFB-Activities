package br.com.pc3;

public class ProdutoTeste {

    public static void main(String[] args) {

        Produto produto = new Produto();
//        produto.adicionar(600);

        Compra compra1 = new Compra(produto, 100);
        Venda venda1 = new Venda(produto, 100);

        Compra compra2 = new Compra(produto, 100);
        Venda venda2 = new Venda(produto, 100);

        compra1.start();
        venda1.start();

        compra2.start();
        venda2.start();
    }
}