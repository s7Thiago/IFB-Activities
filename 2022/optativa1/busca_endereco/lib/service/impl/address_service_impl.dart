import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/repository/address_repository.dart';
import 'package:busca_endereco/service/address_service.dart';

class AddressServiceImpl implements AddressService{

  final AddressRepository repository;

  AddressServiceImpl({required this.repository});


  @override
  Future<Address> getEndereco(String cep) {
    return repository.getEndereco(cep);
  }


}