import java.util.*;																																														

public class Main {
	
	public static void main(String[] args) {
		
		//declrando ad variaveis
		int n, divisor, cont = 0;
		
		//pedindo para que o usuario digite um numero
		//e armazenando ele em n
		System.out.print("Digite n: ");
		n = new Scanner(System.in).nextInt();
		
		//pulando uma linha
		System.out.println("\n");
		
		//loop que incrementa a variavel i enquanto
		//ela for menor ou igual a n
		for(int i = 2; i <= n; i++) {
			
			//verificando se o resto da divisao de n por
			//i é igual a zero. Se sim, então é um divisor
			if(n % (i) == 0) {
				cont++;
				System.out.println("Divisor " + cont + ": " + i);
			}
		}
	}
}
