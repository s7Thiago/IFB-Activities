import 'package:busca_endereco/controller/home_controller.dart';
import 'package:busca_endereco/model/address.dart';
import 'package:busca_endereco/repository/impl/address_repository_impl.dart';
import 'package:busca_endereco/service/impl/address_service_impl.dart';
import 'package:busca_endereco/widgets/app_body.dart';
import 'package:busca_endereco/widgets/custom_input.dart';
import 'package:flutter/material.dart';

main() => runApp(const App());

class App extends StatelessWidget {
  const App({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      home: Home(),
      debugShowCheckedModeBanner: false,
    );
  }
}

// ===================== Home =====================
class Home extends StatefulWidget {
  const Home({Key? key}) : super(key: key);

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final inputController = TextEditingController();
  final controller = HomeController(
    service: AddressServiceImpl(repository: AddressRepositoryImpl()),
  );

  @override
  Widget build(BuildContext ctx) {
    return FutureBuilder(
        future: controller.address,
        builder: (BuildContext ctx, AsyncSnapshot<Address> data) {
          if (data.hasError) {
            return const Center(
              child: Text('Erro'),
            );
          }

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
              body: AppBody(address: data.data!),
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