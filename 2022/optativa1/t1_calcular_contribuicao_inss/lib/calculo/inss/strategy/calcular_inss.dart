import 'package:t1_calcular_contribuicao_inss/calculo/inss/calculo_inss.dart';

class CalcularInss {
  double salario;

  CalcularInss({required this.salario});

  CalculoInss calcular() {
    if (salario > 1212.00 && salario <= 2427.35) {
      return (CalculoInss(
        salario: salario,
        percentual: 0.09,
      ));
    }
    if (salario > 2427.35 && salario <= 3641.03) {
      return CalculoInss(
        salario: salario,
        percentual: 0.12,
      );
    }
    if (salario > 3641.03 && salario <= 7087.22) {
      return CalculoInss(
        salario: salario - 992.22,
        percentual: 0.14,
      );
    }

    return CalculoInss(
      salario: salario,
      percentual: 0.075,
    );
  }
}
