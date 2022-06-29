import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:t3_gasto_mensal/controller/gasto_controller.dart';
import 'package:t3_gasto_mensal/model/gasto_mensal.dart';
import 'package:t3_gasto_mensal/view/cadastro_gasto_mensal.dart';
import 'package:t3_gasto_mensal/view/lista_gasto_mensal.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  // GastoController gastoController = GastoController();
  // GastoMensal gastoMensal =
  //     GastoMensal(null, 2020, "Setembro", "Contade agua", 50.9, "Fixo");
  // gastoController.salvar(gastoMensal).then((res) => print('res: $res'));

  // GastoController gastoController = GastoController();
  // List<GastoMensal> gastos = await gastoController.findAll();
  // print(gastos);

  // GastoMensal gastoMensal =
  //     GastoMensal(1, 2020, "Agosto", "Conta deluz", 90.9, "Fixo");
  // GastoController gastoController = GastoController();
  // gastoController.salvar(gastoMensal).then((res) => print(res));
  // List<GastoMensal> gastos = await gastoController.findAll();
  // print(gastos);

  // GastoController gastoController = GastoController();
  // gastoController.excluir(2).then((res) => print(res));
  // List<GastoMensal> gastos = await gastoController.findAll();
  // print(gastos);

  runApp(MaterialApp(
    home: ListaGastoMensal(),
    theme: ThemeData(
        hintColor: Colors.amber,
        primaryColor: Colors.white,
        inputDecorationTheme: const InputDecorationTheme(
          enabledBorder:
              OutlineInputBorder(borderSide: BorderSide(color: Colors.white)),
          focusedBorder:
              OutlineInputBorder(borderSide: BorderSide(color: Colors.amber)),
          hintStyle: TextStyle(color: Colors.amber),
        )),
  ));
}
