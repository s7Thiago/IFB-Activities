import 'package:busca_endereco/model/address.dart';

abstract class AdressRepository {

Future<Address> getEndereco(String cep);

}