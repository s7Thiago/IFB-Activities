import 'package:flutter/material.dart';
import 'package:flutter_app/http/logging_interceptor.dart';

void main() {
  findAll().then((cursos) => debugPrint('Cursos $cursos'));
  runApp(const App());
}

class App extends StatelessWidget {
  const App({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      routes: {
        
      },
    );
  }
}