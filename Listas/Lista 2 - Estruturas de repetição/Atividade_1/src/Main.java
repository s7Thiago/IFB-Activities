import java.util.*;																										

public class Main
{
	public static void main(String[] args)
	{
		int opcao = 0;
		String[] opcoes = new String[]{"Peixe", "Feijão", "Macarrão", "Frango"};
		String separador = "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::";
		
		do {
			
			
			System.out.println("1 - Peixe\n2 - Feijão\n3 - Macarrão\n4 - Frango");
			
			System.out.print("\n\nDigite a opção: ");
			
			try{
			opcao = new Scanner(System.in).nextInt();
			}catch(InputMismatchException e) {
				System.out.println("\n•••••• Por favor, Digite um número ••••••\n");
			}
			 
			switch(opcao) {
				
				case 1:
					System.out.println("\n\nVocê escolheu " + opcoes[0] + "\n" + separador);
				break;
				
				case 2:
					System.out.println("\n\nVocê escolheu " + opcoes[1] + "\n" + separador);
				break;
				
				case 3:
					System.out.println("\n\nVocê escolheu " + opcoes[2]  + "\n" + separador);
				break;
				
				case 4:
					System.out.println("\n\nVocê escolheu " + opcoes[3]  + "\n" + separador);
				break;
				
				case 5:
					System.out.println(" ");
				break;
				
				default:
				System.out.println("\n\n•••••• Opção inválida ••••••\n\n" + separador);
				
			}
			
		}while(opcao != 5);
		System.out.println("Parando.......");
		
		try{}catch(InputMismatchException e) {}
		
	}
}
