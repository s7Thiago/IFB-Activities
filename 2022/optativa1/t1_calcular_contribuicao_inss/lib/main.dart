import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:t1_calcular_contribuicao_inss/screens/calcular_page.dart';
import 'package:t1_calcular_contribuicao_inss/shared/providers/calc_provider.dart';

main() => runApp(const App());

class App extends StatelessWidget {
  const App({Key? key}) : super(key: key);

  @override
  build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: MultiProvider(
        providers: [
          ChangeNotifierProvider(create: (_) => CalcProvider()),
        ],
        child: const CalcularPage(),
      ),
    );
  }
}
