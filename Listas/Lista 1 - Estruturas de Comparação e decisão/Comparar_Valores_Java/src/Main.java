import java.util.*;

/*CREATED BY THIAGO SOUSA IN 12/03/2018*/

public class Main {

	//6
	public Main(int a, int b, int c, int d) {
		retornaAmplitude(retornaMaior(a, b, c, d), 
						 retornaMenor(a, b, c, d));

		retornaMedia(a, b, c, d);
	}

	//8
	public int retornaMaior(int a, int b, int c, int d){

		if(a > b && a > c && a > d){
			System.out.println("\n\n•A é o maior");
			return a;

		}else if(b > a && b > c && b > d) {
			System.out.println("\n\n•B é o maior");
			return b;

		}else if(c > a && c > b && c > d) {
			System.out.println("\n\n•C é o maior");
			return c;

		}else if(d > a && d > b && d > c) {
			System.out.println("\n\n•D é o maior");
			return d;

		}

		System.out.println("\n\n•Todos são iguais");
		return 0;
	}

	//9
	public int retornaMenor(int a, int b, int c, int d){

		if(a < b && a < c && a < d){
			System.out.println("•A é o menor");
			return a;

		}else if(b < a && b < c && b < d) {
			System.out.println("•B é o menor");
			return b;

		}else if(c < a && c < b && c < d) {
			System.out.println("•C é o menor");
			return c;

		}else if(d < a && d < b && d < c) {
			System.out.println("•D é o menor");
			return d;

		}

		System.out.println("•Todos são iguais");
		return 0;
	}

	//7
	public int retornaAmplitude(int valorA, int valorB) {																						
		int amplitude = valorA - valorB;

		if(amplitude < 0) {

			amplitude = -(amplitude);

			System.out.println("•Amplitude: " + amplitude);
			return amplitude;
		}

		System.out.println("•Amplitude: " + amplitude);
		return amplitude;

	}

	//10
	public int retornaMedia(int a, int b, int c, int d) {
		int soma = a + b + c + d;
		int media = soma/4;

		if(media < 0) {
			media = -(media);

			System.out.println("•Media: " + media);
			return media;
		}

		System.out.println("•Media: " + media);
		return media;
	}

	public static void main(String[] args) {
		int a = 0, b = 0, c = 0, d = 0;
		Scanner leia = new Scanner(System.in);

		//1
		System.out.print("Digite A: ");
		a = leia.nextInt();

		//2
		System.out.print("Digite B: ");
		b = leia.nextInt();

		//3
		System.out.print("Digite C: ");
		c = leia.nextInt();

		//4
		System.out.print("Digite D: ");
		d = leia.nextInt();

		//5
		Main main = new Main(a, b, c, d);
	}
}
