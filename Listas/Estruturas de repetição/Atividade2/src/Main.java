import java.util.*;																																		

public class Main {
	
	
	
	public static void main(String[] args) {
		
		int a = new Scanner(System.in).nextInt(), 
		b = new Scanner(System.in).nextInt(),
		aux = 1,
		resultado = 0;
		
		if(!(b % 2 != 0)) {
			
			System.out.println("Expoente par\n\n");
			
		//Calculo
		for(int i = 1; i <= (b/2); i++) {
			
			aux *= a * a;
			resultado = aux;
			
			if(b == 0) {
				resultado = 1;
				System.out.println("resultado: " + resultado +   "\n----------------\n\n");
			}
			
			if(i == (b/2)) {
			//System.out.println("-----------------\n•Loop " + i + "\naux: " + aux);
			
			System.out.println("resultado: " + resultado +   "\n----------------\n\n");
			}
		}
		//
		} else {
			
			System.out.println("Expoente ímpar\n\n");
			
		for(int i = 1; i <= ((b - 1) / 2); i++) {
			//System.out.println("-----------------\n•Loop " + i + "\naux: " + aux);

			aux *= a * a;
			resultado = aux;
			
			if(b == 0) {
				resultado = 1;
				System.out.println("resultado: " + resultado +   "\n----------------\n\n");
			}

			if(i == ((b - 1) / 2)) {
				
				resultado = resultado * 2;
			System.out.println("resultado: " + (resultado) +   "\n----------------\n\n");
			}
		}
		}
	}
}
