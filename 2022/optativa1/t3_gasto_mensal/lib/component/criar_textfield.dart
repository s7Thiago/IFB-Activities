import 'package:flutter/material.dart';

Widget criarTextField(
  String label,
  TextEditingController controle,
  TextInputType textInputType,
) {
  return TextField(
    controller: controle,
    decoration: InputDecoration(
      labelText: label,
      labelStyle: const TextStyle(color: Colors.amber),
      border: const OutlineInputBorder(),
    ),
    style: const TextStyle(color: Colors.amber, fontSize: 15.0),
    keyboardType: textInputType,
  );
}
