import 'package:flutter/material.dart';
import 'package:web_api/component/curso_item.dart';
import 'package:web_api/http/webclient/curso_webclient.dart';
import 'package:web_api/model/curso.dart';
import 'package:web_api/view/cadastro_curso.dart';

class ListaCurso extends StatefulWidget {
  CursoWebClient _cursoWebClient = CursoWebClient();
  @override
  _ListaCursoState createState() => _ListaCursoState();
}

class _ListaCursoState extends State<ListaCurso> {
  List<Curso> _listaCursos = [];

  @override
  void initState() {
    super.initState();
    widget._cursoWebClient.findAll().then((dados) {
      setState(() {
        _listaCursos = dados;
      });
    });
  }

  _atualizarLista() {
    widget._cursoWebClient.findAll().then((dados) {
      return setState(() => _listaCursos = dados);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        centerTitle: true,
        title: Text("Lista de cursos"),
        backgroundColor: Theme.of(context).primaryColor,
      ),
      body: FutureBuilder<List<Curso>>(
        initialData: _listaCursos,
        future: findAll(),
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
                  children: <Widget>[
                    CircularProgressIndicator(),
                    Text("Carregando..."),
                  ],
                ),
              );
              break;
            case ConnectionState.active:
              break;
            case ConnectionState.done:
              final List<Curso> cursos = snapshot.data!;
              return ListView.builder(
                itemBuilder: (context, index) {
                  final Curso curso = cursos[index];
                  return CursoItem(curso, _listaCursos, index);
                  ;
                },
                itemCount: cursos.length,
              );
              break;
          }
          return Text("Erro");
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.of(context)
              .push(
                MaterialPageRoute(
                  builder: (context) => CadastroCurso(),
                ),
              )
              .then((curso) => setState(() => _atualizarLista()));
        },
        child: Icon(Icons.add),
        backgroundColor: Theme.of(context).primaryColor,
      ),
    );
  }
}
