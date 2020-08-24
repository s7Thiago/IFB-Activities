import 'node.dart';
import 'breadthfirstsearch.dart';

void main() {
//    	Estações
  final furnas = Node("furnas", Node("taguatinga sul", null, null), null);
  final tg_sul =
      Node("taguatinga sul", furnas, Node("aguas_claras", null, null));

  final centro_metropolitano = Node("centro metropolitano", null, null);
  final praca = Node("praça do relogio", centro_metropolitano, null);

  final concessionarias = Node("concessionarias", praca, null);
  final aguas_claras = Node("aguas_claras", concessionarias, tg_sul);

  final arniqueiras = Node("arniqueiras", aguas_claras, null);
  final guara = Node("guara", arniqueiras, Node("shopping", null, null));

  final feira = Node("feira", guara, null);
  final shopping = Node("shopping", feira, null);

  // ignore: unused_local_variable
  final asa_sul = Node("asa_sul", shopping, null);

  //        Success
  var bfs = BreadthFirstSearch(aguas_claras, concessionarias);

  if (bfs.compute())
    print("Path Found!");
  else {
    print("No path found \n:(");
  }
}
