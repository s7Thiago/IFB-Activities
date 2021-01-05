package br.com.pc3.a4;

public class InnerTest {
    public static void main(String[] args) {
        Transporte transporte = new Transporte() {
            @Override
            public double calcularFrete(double valorProduto, int distancia) {
                return (((valorProduto * 0.065) + distancia * 0.045) * 0.16);
            }

        };

        System.out.println("Valor do frete: " + transporte.calcularFrete(500, 5));
    }
}
