
import 'package:t1_calcular_contribuicao_inss/calculo/inss/calculo_inss.dart';

class CalcularInss {

  final double salario;
  final double percentual;

  CalcularInss({required this.salario, required this.percentual});

    @override
    double calcular() {
    if(salario > 1212.00 && salario <= 2427.35) return CalculoInss(salario: salario, percentual: 0.09).calcular();
    if(salario > 3641.03 && salario <= 2427.35) return CalculoInss(salario: salario, percentual: 0.12).calcular();
    if(salario > 3641.03 && salario <= 7087.22) return CalculoInss(salario: salario, percentual: 0.14).calcular();

    return CalculoInss(salario: salario, percentual: 0.075).calcular();
  }
}