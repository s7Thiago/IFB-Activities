import java.util.*;																																			

public class Main {
	
	public static void main(String[] args) {
		
		int a, b, resultado;
		
		do{
		a = new Scanner(System.in).nextInt(); 
		b = new Scanner(System.in).nextInt();
		resultado = 1;
		
		for(int i = b; i > 0; i--) {
			
			resultado = ((resultado--) * a);
		}
		
		System.out.println("Resultado: " + resultado + "\n\n");
		}while(a != 0 && b != 0);
	}
	
}
