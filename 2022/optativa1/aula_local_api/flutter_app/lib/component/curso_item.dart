import 'package:flutter/material.dart';
import 'package:web_api/http/webclient/curso_webclient.dart';
import 'package:web_api/model/curso.dart';
import 'package:web_api/view/cadastro_curso.dart';
import 'package:web_api/view/lista_cursos.dart';

class CursoItem extends StatefulWidget {
  final Curso _curso;
  List<Curso> _listaCursos;
  int _index;
  CursoItem(this._curso, this._listaCursos, this._index);

  @override
  State<CursoItem> createState() => _CursoItemState();
}

class _CursoItemState extends State<CursoItem> {
  Curso? _ultimoRemovido;
  CursoWebClient _cursoWebClient = CursoWebClient();
  _atualizarLista() {
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => ListaCurso(),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Dismissible(
      key: Key(DateTime.now().millisecondsSinceEpoch.toString()),
      background: Container(
        color: Colors.red,
        child: Align(
          alignment: Alignment(-0.9, 0.0),
          child: Icon(
            Icons.delete,
            color: Colors.white,
          ),
        ),
      ),
      direction: DismissDirection.startToEnd,
      child: Card(
        color: Colors.orange[800],
        child: ListTile(
          title: Text(
            widget._curso.nome,
            style: TextStyle(
              fontSize: 16.0,
            ),
          ),
          subtitle: Text(
            widget._curso.cargaHoraria.toString(),
            style: TextStyle(
              fontSize: 12.0,
            ),
          ),
          onTap: () {
            Navigator.push(
              context,
              MaterialPageRoute(
                builder: (context) => CadastroCurso(
                  curso: widget._listaCursos[widget._index],
                ),
              ),
            );
          },
        ),
      ),
      onDismissed: (direction) {
        setState(() {
          mostrarAlerta(context);
        });
      },
    );
  }

  mostrarAlerta(BuildContext context) {
    Widget botaoNao = TextButton(
      child: Text(
        "Não",
        style: TextStyle(color: Colors.white),
      ),
      onPressed: () {
        _atualizarLista();
      },
    );
    Widget botaoSim = TextButton(
      child: Text(
        "Sim",
        style: TextStyle(
          color: Colors.white,
        ),
      ),
      onPressed: () {
        _ultimoRemovido = widget._listaCursos[widget._index];
        widget._listaCursos.removeAt(widget._index);
        _cursoWebClient.excluir(_ultimoRemovido!.id!);
        _atualizarLista();
      },
    );
    AlertDialog alerta = AlertDialog(
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(20.0)),
      backgroundColor: Colors.orange[800],
      title: Text(
        "Aviso",
        style: TextStyle(color: Colors.black),
      ),
      content: Text(
        "Deseja apagar o registro?",
        style: TextStyle(color: Colors.white),
      ),
      actions: [
        botaoNao,
        botaoSim,
      ],
    );
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return alerta;
      },
    );
  }
}
