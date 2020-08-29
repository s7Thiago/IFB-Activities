public class GraphShow {
    public static void main(String[] args) {

        Graph graph = new Graph(true);
        Node a = new Node(0, "0");
        Node b = new Node(1, "1");
        Node c = new Node(2, "2");
        Node d = new Node(3, "3");
        Node e = new Node(4, "4");
        Node f = new Node(5, "5");

        graph.addEdge(a,d);
        graph.addEdge(a,b);
        graph.addEdge(a,c);
        graph.addEdge(c,d);
        graph.addEdge(a,f);

//        graph.breadthFirstSearch(b);
        
//        System.out.println("Using the unmodified version of BFS we get:");
//        graph.breadthFirstSearch(f);
        
        System.out.println("Versão modificada: ");
        graph.breadthFirstSearchModified(c);
    }
}