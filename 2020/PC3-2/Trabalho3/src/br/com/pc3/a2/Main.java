package br.com.pc3.a2;

public class Main {
    public static void main(String[] args) {
        MostraNumero mn = new MostraNumero();
        MostraNumero.MostraNumeroInterno mni = mn.new MostraNumeroInterno();
        System.out.println(mni.getNumero());
    }
}
