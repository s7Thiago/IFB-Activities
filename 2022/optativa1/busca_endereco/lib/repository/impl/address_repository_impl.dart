import 'dart:convert';

import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/repository/address_repository.dart';
import 'package:http/http.dart' as http;

class AddressRepositoryImpl implements AddressRepository {
  @override
  Future<Address> getEndereco(String cep) async {
    var url = Uri.parse('https://viacep.com.br/ws/$cep/json/');
  var response = await http.get(url);
  return Future.delayed(const Duration(milliseconds: 800)).then((v) => Address.fromJson(jsonDecode(response.body)));
  }

}