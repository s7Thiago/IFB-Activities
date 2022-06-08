import 'package:http_interceptor/http_interceptor.dart';
import 'package:http/http.dart';
import 'interceptor/logging_interceptor.dart';

final Client client =
    InterceptedClient.build(interceptors: [LoggingInterceptor()]);
const String baseUrl = '192.168.59.108:8080';
const String api = 'api/v1/cursos';
