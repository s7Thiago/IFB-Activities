import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/repository/address_repository.dart';
import 'package:busca_endereco/service/adress_service.dart';

class AdressServiceImpl implements AdressService{

  final AdressRepository repository;

  AdressServiceImpl({required this.repository});


  @override
  Future<Address> getEndereco(String cep) {
    return repository.getEndereco(cep);
  }


}