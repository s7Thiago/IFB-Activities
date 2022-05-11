import 'package:busca_endereco/model/address.dart';

abstract class AdressService {
  Future<Address> getEndereco(String cep);
}