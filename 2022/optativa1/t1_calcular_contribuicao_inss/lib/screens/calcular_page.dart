import 'package:flutter/material.dart';

import 'package:flutter/material.dart';
import 'package:t1_calcular_contribuicao_inss/shared/widgets/info_box_widget.dart';
import 'package:t1_calcular_contribuicao_inss/shared/widgets/input/input_box.dart';

class CalcularPage extends StatefulWidget {
  const CalcularPage({Key? key}) : super(key: key);

  @override
  _CalcularPageState createState() => _CalcularPageState();
}

class _CalcularPageState extends State<CalcularPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.purple,
      body: Center(
        child: Wrap(
          children: const [
            InfoBoxWidget(
              title: 'Percent. INSS',
              content: '% 18',
            ),
            InfoBoxWidget(
              title: 'Percent. IRPF',
              content: '% 20',
              alignment: Alignment.centerRight,
            ),
            InfoBoxWidget(
              title: 'Total INSS',
              content: '6250.0',
            ),
            InfoBoxWidget(
              title: 'Total IRPF',
              content: '5000.0',
              alignment: Alignment.centerRight,
            ),
            InputBox(),
          ],
        ),
      ),
    );
  }
}
