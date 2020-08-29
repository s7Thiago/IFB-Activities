import 'dart:collection';
import 'node.dart';

// Classe BreadthFirstSearch
/*
 /// algoritmo básico de  breadth first search em java
 */
class BreadthFirstSearch {
  Node startNode;
  Node goalNode;

  BreadthFirstSearch(
    this.startNode,
    this.goalNode,
  );

  bool compute() {
    if (startNode.stationName == goalNode.stationName) {
      print("Goal Node Found!");
      print(startNode);
    }

    Queue<Node> queue = Queue<Node>();
    List<Node> explored = List();
    queue.add(this.startNode);
    explored.add(startNode);

    while (queue.isNotEmpty) {
      Node current = queue.removeFirst();
      if (current.stationName == goalNode.stationName) {
        print(explored);
        return true;
      } else {
        if (current.getChildren().isEmpty)
          return false;
        else
          queue.addAll(current.getChildren());
      }
      explored.add(current);
    }

    return false;
  }
}
