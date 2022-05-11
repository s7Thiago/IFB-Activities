import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/service/adress_service.dart';

class HomeController {
  final AdressService service;
  final String cep;

  Future<Address> get address => service.getEndereco(cep);

  HomeController({
    required this.service,
    required this.cep,
  });
}
