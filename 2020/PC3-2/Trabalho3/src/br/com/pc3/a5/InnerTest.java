package br.com.pc3.a5;

public class InnerTest {
    public static void main(String[] args) {

        ClasseConcreta1 cc1 = new ClasseConcreta1();
        cc1.exibirMensagem(new Mensagem() {
            @Override
            public String retornaMensagem() {
                return "Mensagem qualquer";
            }
        });

    }
}
