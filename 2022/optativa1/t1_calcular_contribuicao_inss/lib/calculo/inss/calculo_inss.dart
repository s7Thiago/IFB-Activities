class CalculoInss {

  final double salario;
  final double percentual;

  CalculoInss({required this.salario, required this.percentual});

  double calcular(){
    return salario * percentual;
  }
}