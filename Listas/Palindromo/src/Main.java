import java.util.*;																																													

public class Main {
	
	public String reverse(String string) {
		String reversed = "";
		
		for(int i = string.length(); i > 0; i--) {
			
			reversed += string.charAt(i-1);
		}
		
		return reversed.toLowerCase();
	}
	
	public boolean ePalindromo(String string) {
		
		return string.equals(reverse(string));
	}
	
	public static void main(String[] args) {
		
		String string;
		int contador = 0;
		
		do {
			
		contador++;
		System.out.print("•" + contador + "\nDigite algo: ");
		string = new Scanner(System.in).nextLine();
		
		System.out.println("Inverso: " + new Main().reverse(string));
		
		String ePalindromo = new Main().ePalindromo(string)? "Sim" : "Não";
		System.out.println("É Palíndromo? " + ePalindromo);
		
		System.out.println("\n°°°°°°°°°°°°°°°°°°°°°°\n");
		
		} while(string != "");
	}
}
