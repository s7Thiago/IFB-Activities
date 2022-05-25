import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/service/address_service.dart';
import 'package:flutter/material.dart';

class HomeController {
  final AddressService service;
  String _cep = '71919180';
  ValueNotifier<Address> addressNotifier = ValueNotifier<Address>(Address());

  set cep (String newCep) {
    _cep = newCep;
    _updateAddress();
  }


  Future<Address> get address => Future.value(addressNotifier.value);

  _updateAddress() async {
    addressNotifier.value = await service.getEndereco(_cep);
    print(addressNotifier.value);
  }

  HomeController({
    required this.service,
  });
}
