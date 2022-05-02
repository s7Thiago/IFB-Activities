import 'package:flutter/material.dart';
import 'package:t1_calcular_contribuicao_inss/screens/calcular_page.dart';

main () => runApp(const App());

class App extends StatelessWidget {
  const App({ Key? key }) : super(key: key);

  @override
  build(BuildContext context) {
    return const MaterialApp(
      debugShowCheckedModeBanner: false,
      home: CalcularPage(),
    );
  }
}