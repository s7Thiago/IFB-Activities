import 'package:flutter/material.dart';

class TextFieldComponent extends StatelessWidget {
  final String? label;
  final TextEditingController? controller;
  final TextInputType? textInputType;
  final IconData? icon;
  final String? hintText;
  TextFieldComponent(
      {this.controller,
      this.label,
      this.textInputType,
      this.icon,
      this.hintText});
  @override
  Widget build(BuildContext context) {
    return TextField(
      controller: controller,
      decoration: InputDecoration(
        labelText: label,
        hintText: hintText,
        labelStyle: TextStyle(color: Colors.orange[800]),
        border: OutlineInputBorder(),
        icon: Icon(icon),
      ),
      style: TextStyle(color: Colors.orange[800], fontSize: 15.0),
      keyboardType: textInputType ?? TextInputType.text,
    );
  }
}
