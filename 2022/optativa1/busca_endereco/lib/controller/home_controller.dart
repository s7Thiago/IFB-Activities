import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/service/address_service.dart';

class HomeController {
  final AddressService service;
  String _cep = '';

  Future<Address> get address => service.getEndereco(_cep);
  set cep (String newCep) => _cep = newCep;

  HomeController({
    required this.service,
  });
}
