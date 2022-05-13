import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/widgets/address_part.dart';
import 'package:flutter/material.dart';

class AppBody extends StatelessWidget {
  final Address address;

  const AppBody({
    Key? key,
    required this.address,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          AddressPart(
            title: 'logradouro',
            content: address.logradouro!,
          ),
          AddressPart(
            title: 'complemento',
            content: address.complemento!,
          ),
          AddressPart(
            title: 'bairro',
            content: address.bairro!,
          ),
          AddressPart(
            title: 'localidade',
            content: address.localidade!,
          ),
          AddressPart(
            title: 'uf',
            content: address.uf!,
          ),
          AddressPart(
            title: 'IBGE',
            content: address.ibge!,
          ),
          AddressPart(
            title: 'gia',
            content: address.gia!,
          ),
          AddressPart(
            title: 'ddd',
            content: address.ddd!,
          ),
          AddressPart(
            title: 'siafi',
            content: address.siafi!,
          ),
        ],
      ),
    );
  }
}