import 'package:flutter/material.dart';
import 'package:t3_gasto_mensal/model/gasto_mensal.dart';

class GastoItem extends StatelessWidget {
  final GastoMensal _gastoMensal;
  const GastoItem(this._gastoMensal);
  @override
  Widget build(BuildContext context) {
    return Card(
      color: Colors.amber,
      child: ListTile(
        title: Text(
          _gastoMensal.finalidade,
          style: const TextStyle(
            fontSize: 16.0,
          ),
        ),
        subtitle: Text(
          _gastoMensal.valor.toStringAsFixed(2),
          style: const TextStyle(
            fontSize: 12.0,
          ),
        ),
      ),
    );
  }
}
