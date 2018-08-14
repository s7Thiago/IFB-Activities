import java.util.*;																																			

public class Main {
	
	//metodo principal
	public static void main(String[] args) {
		
		int a, b, resultado;
		
		//A estrutura do execota o código do seu corpo
		//enquanto a comparação no whike for falsa
		do{
			
		//armazena a entrada do teclado em a
		a = new Scanner(System.in).nextInt(); 
		
		//armazena a emtrada do teclado em b
		b = new Scanner(System.in).nextInt();
		
		//inicializando a variável resultado com 1
		resultado = 1;
		
		//efetua os calculos repetidas vezes
		for(int i = b; i > 0; i--) {
			
			//faz a multiplicação de a * a 'b' vezes
			resultado = ((resultado--) * a);
		}
		
		//mostra uma mensagem com o resultado
		System.out.println("Resultado: " + resultado + "\n\n");
		
		//o while finaliza a execução se, e somente se
		//'a = 0' e 'b = 0'
		}while(a != 0 && b != 0);
		
	}//fim do main
}
