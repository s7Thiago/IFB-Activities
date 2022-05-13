import 'package:busca_endereco/model/address.dart';

abstract class AddressRepository {

Future<Address> getEndereco(String cep);

}