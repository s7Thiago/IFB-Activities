import 'package:t1_calcular_contribuicao_inss/calculo/irpf/calculo_irpf.dart';

class CalcularIrpf {
  double salario;
  int qtdeDependentes;

  CalcularIrpf({
    required this.salario,
    this.qtdeDependentes = 0,
  });

  CalculoIrpf calcular() {
    if (salario >= 1903.99 && salario <= 2826.65) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.075,
        parcelaADeduzir: 142.8,
        qtdeDependentes: qtdeDependentes,
      );
    }

    if (salario > 2826.65 && salario <= 3751.05) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.15,
        parcelaADeduzir: 354.8,
        qtdeDependentes: qtdeDependentes,
      );
    }

    if (salario > 3751.05 && salario <= 4664.68) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.225,
        parcelaADeduzir: 636.13,
        qtdeDependentes: qtdeDependentes,
      );
    }

    if (salario > 4664.68) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.275,
        parcelaADeduzir: 869.36,
        qtdeDependentes: qtdeDependentes,
      );
    }

    return CalculoIrpf(
        salario: salario,
        qtdeDependentes: qtdeDependentes,
        aliquota: 0.00,
        parcelaADeduzir: 0.00);
  }
}
