import 'package:busca_endereco/model/address.dart';

abstract class AddressService {
  Future<Address> getEndereco(String cep);
}