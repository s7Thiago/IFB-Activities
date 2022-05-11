import 'package:busca_endereco/controller/home_controller.dart';
import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/repository/impl/address_repository_impl.dart';
import 'package:busca_endereco/service/impl/address_service_impl.dart';
import 'package:flutter/material.dart';

main() => runApp(App());

class App extends StatelessWidget {
  @override
  Widget build(BuildContext ctx) {
    return MaterialApp(
      home: Home(),
      debugShowCheckedModeBanner: false,
    );
  }
}

// ===================== Home =====================
class Home extends StatefulWidget {
  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final inputController = TextEditingController();
  final controller = HomeController(
    service: AdressServiceImpl(repository: AddressRepositoryImpl()),
    cep: '71919180',
  );


  @override
  Widget build(BuildContext ctx) {
    return FutureBuilder(
        future: controller.address,
        builder: (BuildContext ctx, AsyncSnapshot<Address> data) {
          if (!data.hasData) {
            return Container(
              height: double.maxFinite,
              width: double.maxFinite,
              color: Colors.blueGrey.withOpacity(1),
              child: const Center(
                child: SizedBox(
                  width: 200,
                  child: CircularProgressIndicator(
                    color: Colors.white,
                    strokeWidth: 10,
                  ),
                ),
              ),
            );
          } else {
            return Scaffold(
              appBar: AppBar(
                backgroundColor: Colors.blueGrey,
                title: const Text('Busca de endereços'),
                centerTitle: true,
                leading: const Icon(Icons.map),
                elevation: 0,
              ),
              body: AppBody(adress: data.data!),
              bottomNavigationBar: Padding(
                padding: const EdgeInsets.symmetric(horizontal: 16),
                child: Stack(
                  fit: StackFit.loose,
                  alignment: Alignment.center,
                  children: [
                    Positioned(
                      child: CustomInput(controller: inputController),
                    ),
                    Positioned(
                      left: MediaQuery.of(context).size.width * .63,
                      child: FloatingActionButton(
                        onPressed: () {},
                        child: const Icon(Icons.search),
                      ),
                    )
                  ],
                ),
              ),
            );
          }
        });
  }
}

// ===================== body =====================
class AppBody extends StatelessWidget {
  final Address adress;

  const AppBody({
    Key? key,
    required this.adress,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          AdressPart(
            title: 'logradouro',
            content: adress.logradouro!,
          ),
          AdressPart(
            title: 'complemento',
            content: adress.complemento!,
          ),
          AdressPart(
            title: 'bairro',
            content: adress.bairro!,
          ),
          AdressPart(
            title: 'localidade',
            content: adress.localidade!,
          ),
          AdressPart(
            title: 'uf',
            content: adress.uf!,
          ),
          AdressPart(
            title: 'IBGE',
            content: adress.ibge!,
          ),
          AdressPart(
            title: 'gia',
            content: adress.gia!,
          ),
          AdressPart(
            title: 'ddd',
            content: adress.ddd!,
          ),
          AdressPart(
            title: 'siafi',
            content: adress.siafi!,
          ),
        ],
      ),
    );
  }
}

// ===================== custom input =====================
class AdressPart extends StatelessWidget {
  final String title;
  final String content;

  const AdressPart({
    Key? key,
    required this.title,
    required this.content,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ListTile(
      title: Text(title),
      subtitle: Text(content),
    );
  }
}

// ===================== custom input =====================
class CustomInput extends StatelessWidget {
  final TextEditingController controller;

  const CustomInput({Key? key, required this.controller,}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(16),
      padding: const EdgeInsets.only(left: 16, bottom: 2),
      alignment: Alignment.center,
      height: 50,
      width: MediaQuery.of(context).size.width * .5,
      child: TextField(
        controller: controller,
        cursorColor: Colors.white,
        maxLength: 8,
        maxLines: 1,
        cursorHeight: 25,
        style: const TextStyle(color: Colors.white),
        decoration: const InputDecoration(border: InputBorder.none),
      ),
      decoration: const BoxDecoration(
          color: Colors.blueGrey,
          borderRadius: BorderRadius.all(Radius.circular(100))),
    );
  }
}
