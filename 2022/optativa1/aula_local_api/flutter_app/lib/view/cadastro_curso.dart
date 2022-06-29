import 'package:flutter/material.dart';
import 'package:web_api/component/dropdown_component.dart';
import 'package:web_api/component/textfield_component.dart';
import 'package:web_api/http/webclient/curso_webclient.dart';
import 'package:web_api/model/curso.dart';
import 'package:web_api/view/lista_cursos.dart';

class CadastroCurso extends StatefulWidget {
  final Curso? curso;
  CadastroCurso({this.curso});

  @override
  _CadastroCursoState createState() => _CadastroCursoState();
}

class _CadastroCursoState extends State<CadastroCurso> {
  TextEditingController _nomeController = TextEditingController();
  TextEditingController _cargaHorariaController = TextEditingController();
  TextEditingController _modalidadeController = TextEditingController();
  CursoWebClient _cursoWebClient = CursoWebClient();

  var _modalidades = ["PRESENCIAL", "SEMI_PRESENCIAL", "EAD"];
  var _modalidadeSelecionada = "PRESENCIAL";
  int? _id;

  _displaySnackBar(BuildContext context, String mensagem) {
    final snackBar = SnackBar(
      content: Text(mensagem),
      backgroundColor: Colors.green[900],
    );
    ScaffoldMessenger.of(context).showSnackBar(snackBar);
  }

  _salvar(BuildContext context) {
    final curso = Curso(_nomeController.text,
        int.parse(_cargaHorariaController.text), _modalidadeSelecionada,
        id: _id ?? null);
    setState(() {
      _cursoWebClient.salvar(curso).then((res) {
        _displaySnackBar(context, res.toString());
        Navigator.pushReplacement(
          context,
          MaterialPageRoute(
            builder: (context) => ListaCurso(),
          ),
        );
      });
    });
  }

  @override
  void initState() {
    if (widget.curso != null) {
      _id = widget.curso!.id;
      _nomeController.text = widget.curso!.nome;
      _cargaHorariaController.text = widget.curso!.cargaHoraria.toString();
      _modalidadeSelecionada = widget.curso!.modalidade;
    } else {
      _id = null;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Cadastro de cursos'),
        centerTitle: true,
        backgroundColor: Theme.of(context).primaryColor,
      ),
      body: SingleChildScrollView(
        child: Column(
          children: [
            Padding(
              padding: EdgeInsets.all(16.0),
              child: TextFieldComponent(
                label: 'Nome',
                controller: _nomeController,
                hintText: 'Nome do curso',
                icon: Icons.abc,
              ),
            ),
            Padding(
              padding: EdgeInsets.all(16.0),
              child: TextFieldComponent(
                label: 'Carga horária',
                controller: _cargaHorariaController,
                textInputType: TextInputType.number,
                hintText: '000',
                icon: Icons.numbers_rounded,
              ),
            ),
            Container(
              padding: EdgeInsets.all(10.0),
              child: Row(
                children: [
                  Text(
                    'Modalidade',
                    style: TextStyle(color: Theme.of(context).primaryColor),
                  ),
                  Padding(
                    padding: EdgeInsets.only(left: 15.0),
                    child: DropdownComponent(
                      elementos: _modalidades,
                      itemSelecionado: _modalidadeSelecionada,
                      onChanged: (novaModalidade) {
                        setState(() => _modalidadeSelecionada = novaModalidade);
                      },
                    ),
                  ),
                ],
              ),
            ),
            Padding(
              padding: EdgeInsets.all(16.0),
              child: SizedBox(
                width: double.maxFinite,
                child: ElevatedButton.icon(
                  onPressed: () {
                    _salvar(context);
                  },
                  style: ElevatedButton.styleFrom(
                    primary: Theme.of(context).primaryColor,
                    shape: const RoundedRectangleBorder(
                      borderRadius: BorderRadius.all(Radius.circular(10.0)),
                    ),
                    onPrimary: Colors.green,
                  ),
                  label: const Text(
                    'Salvar',
                    style: TextStyle(
                      color: Colors.white,
                    ),
                  ),
                  icon: const Icon(
                    Icons.save,
                    color: Colors.white,
                  ),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
