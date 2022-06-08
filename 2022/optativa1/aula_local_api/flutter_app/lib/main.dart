import 'package:flutter/material.dart';
import 'package:web_api/view/lista_cursos.dart';

void main() {
  runApp(CursoApp());
}

class CursoApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        primaryColor: Colors.orange[800],
        colorScheme: ColorScheme.fromSwatch().copyWith(
          secondary: Colors.orange[800], // Your accent color
        ),
        buttonTheme: ButtonThemeData(
          buttonColor: Colors.orange[800],
          textTheme: ButtonTextTheme.primary,
        ),
      ),
      home: ListaCurso(),
    );
  }
}
