import java.util.*;                                                                                                                                                                                                    

public class Main {
    
	public static void main(String[] args) {
      
      //declarando m e n
      int m = 0, n = 0, aux = 0;
      
      //pedindo que o usuario digite m, e armazenando 
      //a entrada do teclado em m
      System.out.print("Digite m: ");
      m = new Scanner(System.in).nextInt();
      
      //pedindo que o usuario digite m, e armazenando 
      //a entrada do teclado em n
      System.out.print("Digite n: ");
      n = new Scanner(System.in).nextInt();
      
      //calculando
      while(n != 0) {
          aux = m % n;
          m = n;
          n = aux;
     }
     
     System.out.println("\nm.d.c: " + m);
   }
}
