/*
 /// A classe Node representa uma estação
 /// cada estação tem uma string representando
 /// o nome da estação, e um ArrayList que
 /// serve para armazenar todos os Nodes filhos
 /// instanciados
 */
class Node {
  //	  É um identificador único do Node
  final stationName;

  //    Os Nodes filhos os quais este node está diretamente conectado.
  Node leftChild;
  Node rightChild;

  Node(this.stationName, this.rightChild, this.leftChild);

  List<Node> getChildren() {
    //  Um ArrayList contendo os Nodes filhos desde Node
    List<Node> childNodes = List();

    if (this.leftChild != null) {
      childNodes.add(leftChild);
    }
    if (this.rightChild != null) {
      childNodes.add(rightChild);
    }
    return childNodes;
  }

  //    Um método auxiliar que nos
  //    permite remover qualquer Node filho
  //	  da lista de um Node referenciado
  bool removeChild(Node n) {
    return false;
  }

  @override
  String toString() {
    return this.stationName;
  }
}
