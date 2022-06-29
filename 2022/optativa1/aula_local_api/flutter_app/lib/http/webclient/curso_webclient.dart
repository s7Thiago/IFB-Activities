import 'dart:convert';

import 'package:http/http.dart';
import 'package:web_api/model/curso.dart';

import '../web_client.dart';

class CursoWebClient {
  Future<List<Curso>> findAll() async {
    final Response response =
        await client.get(Uri.http(baseUrl, api)).timeout(Duration(seconds: 5));
    final List<dynamic> decodedJson =
        jsonDecode(utf8.decode(response.bodyBytes));
    return decodedJson.map((dynamic json) => Curso.fromJson(json)).toList();
  }

  Future<Curso> salvar(Curso curso) async {
    Response response;
    if (curso.id == null) {
      response = await client.post(Uri.http(baseUrl, api),
          headers: {
            'Content-type': 'application/json',
          },
          body: jsonEncode(curso.toJson()));
    } else {
      Uri alterar = Uri.http(baseUrl, api + "/${curso.id}");
      response = await client.put(alterar,
          headers: {
            'Content-type': 'application/json',
          },
          body: jsonEncode(curso.toJson()));
    }
    return Curso.fromJson(jsonDecode(response.body));
  }

  Future<Null> excluir(int id) async {
    Response response;
    Uri deletar = Uri.http(baseUrl, api + "/${id}");
    response = await client.delete(deletar, headers: {
      'Content-type': 'application/json',
    });
  }
}
