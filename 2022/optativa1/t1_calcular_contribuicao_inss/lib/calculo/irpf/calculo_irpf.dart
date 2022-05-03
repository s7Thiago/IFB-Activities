class CalculoIrpf {
  double salario;
  double aliquota;
  final int qtdeDependentes;
  double parcelaADeduzir;

  CalculoIrpf({
    required this.salario,
    required this.aliquota,
    required this.qtdeDependentes,
    required this.parcelaADeduzir,
  });

  double calcular() {
    double resultado =
        ((salario * aliquota) - parcelaADeduzir) - (qtdeDependentes * 189.59);
    return resultado;
  }
}
