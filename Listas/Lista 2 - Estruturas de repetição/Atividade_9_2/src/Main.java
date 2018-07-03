import java.util.*;																																																																																																				

public class Main {
		
		//método que verifica se o número do parâmetro é primo
		public int ehPrimo(int num) {
				int cont = 0;
				
				for(int i = 1; i <= num; i++) {
						
						//verificando se num é divisível por cada i
						if(!(num % i == 0)) {
								cont++;
						}
				}
				
				//retorna quantos divisores foram encontrados
				return cont;
		}
		
	public static void main(String[] args) {
			Main m = new Main();
			
			int n, div1, div2;
			
			System.out.print("Digite n: ");
			n = new Scanner(System.in).nextInt();
			
			//econtra o menor número primo que é maior do que n
			for(int i = n; (m.ehPrimo(i) != 2); i++) {
					
					if(m.ehPrimo(i) < 3) {
					System.out.println(i);
					}
			}
	}
}
