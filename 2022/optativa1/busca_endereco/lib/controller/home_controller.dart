import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/service/adress_service.dart';

class HomeController {
  final AdressService service;
  String _cep = '';

  Future<Address> get address => service.getEndereco(_cep);
  set cep (String newCep) => _cep = newCep;

  HomeController({
    required this.service,
  });
}
