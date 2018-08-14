import java.util.*;																																

public class Main {


	public static void main(String[] args) {

		//declarando variáveis auxiliares
		int n, result = 0;

		//exibindo mensagem e armazenando a 
		//entrada do teclado em n
		System.out.print("Digite n: ");
		n = new Scanner(System.in).nextInt();
		
		//pulando linha
		System.out.println("\n");
		
		//somando todos os números de 1 a n
		//e armazenando em result
		for(int i = 1; i <= n; i++) {

			result = result += i;
			
			//imprimindo o valor final de result
			System.out.println("Resultado: " + result);
		}
	}
}
