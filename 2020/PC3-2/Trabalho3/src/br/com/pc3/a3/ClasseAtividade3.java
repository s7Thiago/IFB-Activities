package br.com.pc3.a3;

public class ClasseAtividade3 {

    public void metodoComInnerClass(){
        final int numero = 12348;

        class ClasseInternaComoVariavelLocal {

            public void imprimir(){
                System.out.println("Método da inner class exibindo o valor da variáve local: " + numero);
            }

        }

        ClasseInternaComoVariavelLocal civl = new ClasseInternaComoVariavelLocal();
        civl.imprimir();

    }

}
