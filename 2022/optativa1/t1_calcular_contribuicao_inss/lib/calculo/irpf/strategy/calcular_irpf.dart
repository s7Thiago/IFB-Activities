import 'package:t1_calcular_contribuicao_inss/calculo/irpf/calculo_irpf.dart';

class CalcularIrpf {
  double salario;
  double aliquota;

  CalcularIrpf({
    required this.salario,
    required this.aliquota,
  });

  double calcular() {
    if (salario >= 1903.99 && salario <= 2826.65) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.075,
        parcelaADeduzir: 142.8,
      ).calcular();
    }

    if (salario > 2826.65 && salario <= 3751.05) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.15,
        parcelaADeduzir: 354.8,
      ).calcular();
    }

    if (salario > 3751.05 && salario <= 4664.68) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.225,
        parcelaADeduzir: 636.13,
      ).calcular();
    }

    if (salario > 4664.68) {
      return CalculoIrpf(
        salario: salario,
        aliquota: 0.275,
        parcelaADeduzir: 869.36,
      ).calcular();
    }

    return CalculoIrpf(salario: salario).calcular();
  }
}
