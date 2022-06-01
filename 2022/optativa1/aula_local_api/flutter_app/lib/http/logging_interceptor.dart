import 'dart:convert';

import 'package:flutter/foundation.dart';
import 'package:flutter_app/model/curso.dart';
import 'package:http/http.dart';
import 'package:http_interceptor/http_interceptor.dart';

class LoggingInterceptor implements InterceptorContract {
  @override
  Future<RequestData> interceptRequest({RequestData? data}) async {
    if (data != null) {
      debugPrint('Request');
      debugPrint('url: ${data.url}');
      debugPrint('headers: ${data.headers}');
      debugPrint('body: ${data.body}');
      return data;
    }
    return data!;
  }

  @override
  Future<ResponseData> interceptResponse({ResponseData? data}) async {
    if (data != null) {
      debugPrint('Response');
      debugPrint('status code: ${data.statusCode}');
      debugPrint('headers: ${data.headers}');
      debugPrint('body: ${data.body}');
      return data;
    }
    return data!;
  }
}

Future<List<Curso>> findAll() async {
  final Client client = InterceptedClient.build(
    interceptors: [LoggingInterceptor()],
  );

  final Response response = await client.get(
    Uri.http('localhost:8080', 'api/v1/cursos'),
    headers: {
      "Access-Control-Allow-Origin" : "*",
    }
  );

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
