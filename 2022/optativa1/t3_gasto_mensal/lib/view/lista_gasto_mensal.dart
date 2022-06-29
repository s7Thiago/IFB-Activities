import 'package:flutter/material.dart';
import 'package:t3_gasto_mensal/controller/gasto_controller.dart';
import 'package:t3_gasto_mensal/model/gasto_mensal.dart';
import 'package:t3_gasto_mensal/view/cadastro_gasto_mensal.dart';
import 'package:t3_gasto_mensal/view/gasto_item.dart';

class ListaGastoMensal extends StatefulWidget {
  @override
  _ListaGastoMensalState createState() => _ListaGastoMensalState();
}

class _ListaGastoMensalState extends State<ListaGastoMensal> {
  final GastoController _gastoController = GastoController();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        title: const Text("\$ Gasto mensal \$"),
        backgroundColor: Colors.amber,
        centerTitle: true,
        automaticallyImplyLeading: false,
      ),
      body: FutureBuilder<List<GastoMensal>>(
        initialData: const [],
        future: _gastoController.findAll(),
// ignore: missing_return
        builder: (context, snapshot) {
          switch (snapshot.connectionState) {
            case ConnectionState.none:
              break;
            case ConnectionState.waiting:
              return Center(
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  crossAxisAlignment: CrossAxisAlignment.center,
                  children: const <Widget>[
                    CircularProgressIndicator(),
                    Text("Carregando..."),
                  ],
                ),
              );
              break;
            case ConnectionState.active:
              break;
            case ConnectionState.done:
              final List<GastoMensal> gastos = snapshot.data!;
              return ListView.builder(
                itemBuilder: (context, index) {
                  final GastoMensal gastoMensal = gastos[index];
                  return GastoItem(gastoMensal);
                },
                itemCount: gastos.length,
              );
              break;
          }
          return const Text("Erro");
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.of(context).push(
            MaterialPageRoute(
              builder: (context) => Cadastro(),
            ),
          );
        },
        backgroundColor: Colors.amber,
        child: Icon(Icons.add),
      ),
    );
  }
}
