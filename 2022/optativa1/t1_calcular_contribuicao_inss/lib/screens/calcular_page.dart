import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:t1_calcular_contribuicao_inss/shared/providers/calc_provider.dart';
import 'package:t1_calcular_contribuicao_inss/shared/widgets/info_box_widget.dart';
import 'package:t1_calcular_contribuicao_inss/shared/widgets/input/input_box.dart';

class CalcularPage extends StatelessWidget {
  const CalcularPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {

    final totalInss = Provider.of<CalcProvider>(context, listen: true).totalInss;
    final percentualInss = Provider.of<CalcProvider>(context, listen: true).percentualInss;

    final totalIrpf = Provider.of<CalcProvider>(context, listen: true).totalIrpf;
    final percentualIrpf = Provider.of<CalcProvider>(context, listen: true).percentualIrpf;

    return Scaffold(
      backgroundColor: Colors.purple,
      body: Center(
        child: Wrap(
          children: [
            InfoBoxWidget(
              title: '% INSS',
              content: '% ${(percentualInss * 100).toStringAsFixed(2)}',
            ),
            InfoBoxWidget(
              title: '% IRPF',
              content: '% ${(percentualIrpf * 100).toStringAsFixed(2)}',
              alignment: Alignment.centerRight,
            ),
            InfoBoxWidget(
              title: 'Total INSS',
              content: totalInss.toStringAsFixed(2),
            ),
            InfoBoxWidget(
              title: 'Total IRPF',
              content: totalIrpf.toStringAsFixed(2),
              alignment: Alignment.centerRight,
            ),
            InputBox(),
          ],
        ),
      ),
    );
  }
}
