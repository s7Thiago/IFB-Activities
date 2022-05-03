import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:t1_calcular_contribuicao_inss/calculo/inss/calculo_inss.dart';
import 'package:t1_calcular_contribuicao_inss/calculo/inss/strategy/calcular_inss.dart';
import 'package:t1_calcular_contribuicao_inss/calculo/irpf/calculo_irpf.dart';
import 'package:t1_calcular_contribuicao_inss/calculo/irpf/strategy/calcular_irpf.dart';
import 'package:t1_calcular_contribuicao_inss/shared/providers/calc_provider.dart';
import 'package:t1_calcular_contribuicao_inss/shared/widgets/input/custom_input_widget.dart';

class InputBox extends StatelessWidget {

  InputBox({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final calcProvider = Provider.of<CalcProvider>(context);

    return Row(
      children: [
        CustomInputWidget(
          content: 'Content 1',
          title: 'Salário',
          onChanged: (content) {
            if (content.isEmpty) content = '0';

            calcProvider.salario = double.parse(content);

            CalcularInss calcularInss = CalcularInss(
              salario: calcProvider.salario,
            );

            CalculoInss calculo = calcularInss.calcular();
            double resultado = calculo.calcular();
            double percentual = calculo.percentual;

            calcProvider.totalInss = resultado;
            calcProvider.percentualInss = percentual;
          },
        ),
        CustomInputWidget(
          content: 'Content 2',
          title: 'Dependentes',
          onChanged: (content) {
            if (content.isEmpty) content = '0';

            CalcularIrpf calcularIrpf = CalcularIrpf(
              qtdeDependentes: int.parse(content),
              salario: calcProvider.salario,
            );

            CalculoIrpf calculo = calcularIrpf.calcular();
            double resultado = calculo.calcular();
            double aliquota = calculo.aliquota;

            calcProvider.totalIrpf = resultado;
            calcProvider.percentualIrpf = aliquota;
          },
        ),
      ],
    );
  }
}
