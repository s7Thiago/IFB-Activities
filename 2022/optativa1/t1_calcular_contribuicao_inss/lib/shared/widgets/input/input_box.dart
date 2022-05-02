import 'package:flutter/material.dart';
import 'package:t1_calcular_contribuicao_inss/shared/widgets/input/custom_input_widget.dart';

class InputBox extends StatelessWidget {
  const InputBox({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Row(
      children: const [
        CustomInputWidget(
          content: 'Content 1',
          title: 'Salário',
        ),
        CustomInputWidget(
          content: 'Content 2',
          title: 'Dependentes',
        ),
      ],
    );
  }
}
