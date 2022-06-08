import 'dart:convert';

import 'package:http/http.dart';
import 'package:http_interceptor/http_interceptor.dart';
import 'package:web_api/http/interceptor/logging_interceptor.dart';

class Curso {
  int? id;
  String nome;
  int cargaHoraria;
  String modalidade;
  Curso(this.nome, this.cargaHoraria, this.modalidade, {this.id});
  Map<String, dynamic> toJson() => {
        "id": id,
        "nome": nome,
        "cargaHoraria": cargaHoraria,
        "modalidade": modalidade,
      };
  Curso.fromJson(Map<String, dynamic> json)
      : nome = json["nome"],
        cargaHoraria = json["cargaHoraria"],
        modalidade = json["modalidade"],
        id = json["id"];
  @override
  String toString() {
    return "Curso: $nome \n Carga Horária: $cargaHoraria \n modalidade: $modalidade";
  }
}

Future<List<Curso>> findAll() async {
  final Client client =
      InterceptedClient.build(interceptors: [LoggingInterceptor()]);
  final Response response =
      await client.get(Uri.http('192.168.59.108:8080', 'api/v1/cursos'));
  final List<dynamic> decodedJson = jsonDecode(utf8.decode(response.bodyBytes));
  final List<Curso> cursos = [];
  for (Map<String, dynamic> cursoJson in decodedJson) {
    final Curso curso = Curso(
      cursoJson['nome'],
      cursoJson['cargaHoraria'],
      cursoJson['modalidade'],
      id: cursoJson['id'],
    );
    cursos.add(curso);
  }
  return cursos;
}
