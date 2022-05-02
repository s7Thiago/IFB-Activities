class CalculoIrpf {
  double salario;
  double aliquota;
  final int qtdeDependentes;
  double parcelaADeduzir;

  CalculoIrpf({
    required this.salario,
    this.aliquota = 0.00,
    this.qtdeDependentes = 0,
    this.parcelaADeduzir = 0.00,
  });

  double calcular() {
    return ((salario * aliquota) - parcelaADeduzir) -
        (qtdeDependentes * 189.59);
  }
}
