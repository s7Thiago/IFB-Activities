import java.util.*;                                                                                                                                                        

public class Main {
    
	public static void main(String[] args) {
        
        //declarando variaveis
        int tam, vet[], numNotOrdened = 0;
        
        //armazenando a entrada do teclado em tam
        System.out.print("Digite o numero de elementos: ");
        tam = new Scanner(System.in).nextInt();
        
        //definindo que o vetor vet[] terá tamanho tam
        vet = new int[tam];
        
        //pulando uma linha
        System.out.println("\n");
        
        //pedindo para o usuario popular o vetor
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Elemento " + (i + 1) + ": ");
            vet[i] = new Scanner(System.in).nextInt();
        }
        
        //pulando uma linha
        System.out.println("\n");
        
        //verificando se o vetor é ordenado
        for(int i = 0; i < (vet.length - 1); i++) {
            
            //se o numero (vet[i]) i do vetor for menor ou igual ao
            //posterior(vet[i + 1]), somente mostre uma mensagem
            if(vet[i] <= vet [i + 1]) {
                System.out.println(vet[i] +  " <= " + vet[i + 1]);
            } else {
                //caso contrario, mostre uma mensagem informativa
                //e some um a variavel que conta as não ordenações
                System.out.println(vet[i] +  " > " + vet[i + 1]);
                numNotOrdened++;
            }
        }//verificado
		
        //se o numero de não ordenações contado for maior do que zero
        if(numNotOrdened > 0) {
            
            //zerando contador de desordenções
            numNotOrdened = 0;
            
            //imprima que a coleção não é ordenada em ordem crescente
            System.out.println("\n\nEsta coleção não está ordenada em ordem crescente!");
            
            //verifica se o vetor é ordenado em ordem decrescente, já
            //que em relação á ordem crescente foram contabilizadas desordens
            System.out.println("\n\nVerificando se o vetor é \nordenado em ordem decrescente...\n");
            for(int i = 0; i > vet.length; i--) {
                
                //se o numero (vet[i]) i do vetor for maior ou igual ao
                //posterior(vet[i + 1]), somente mostre uma mensagem
                if(vet[i] >= vet[i + 1]) {
                    System.out.println(vet[i] +  " >= " + vet[i + 1]);
                } else {
                    //caso contrario, mostre uma mensagem informativa
                    //e some um a variavel que conta as não ordenações
                    System.out.println(vet[i] +  " < " + vet[i + 1]);
                    numNotOrdened++;
                }
            }//verificado
            
            //se o numero de não ordenações contado for maior do que zero
            if(numNotOrdened > 0) {
                //avise que o vetor de fato edtá desordenado
                System.out.println("\nO vetor realmente não é ordenado!");
            } else {
                //informe que é ordenado do maior para o menor
                System.out.println("\n\nO vetor está ordenado, mas em ordem decrescente.");
            }
            
        } else {
            //se não for maior do que zero, diga que é ordenado
            System.out.println("\n\nEsta coleção está ordenada em ordem crescente");
        }
	}
}
