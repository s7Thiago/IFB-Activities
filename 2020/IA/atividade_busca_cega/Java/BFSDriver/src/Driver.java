 /* Our main driver class which instantiates some example nodes
 * and then performs the breadth first search upon these newly created
 * nodes.
 */
public class Driver {

    public static void main(String args[]){
//        Node station1 = new Node("Westminster", null, null);
//        Node station2 = new Node("Waterloo", station1, null);
//        Node station3 = new Node("Trafalgar Square", station1, station2);
//        Node station4 = new Node("Canary Wharf", station2, station3);
//        Node station5 = new Node("London Bridge", station4, station3);
//        Node station6 = new Node("Tottenham Court Road", station5, station4);
    	
//    	Estações
    	Node station12 = new Node("Samambaia sul", null, null);
    	
    	Node station11 = new Node("Centro metropolitano", null, null);
    	Node station10 = new Node("Praça do relógio", station11, null);
    	Node station9 = new Node("Concessionárias", station10, null); // 8 e 10
    	
    	Node station8 = new Node("Furnas", station12, null); // 7 e 
    	Node station7 = new Node("Taguatinga Sul", station9, null); // 6 e 8
    	Node station6 = new Node("Águas claras", station8, null); // 5 e 7
    	
    	Node station5 = new Node("Arniqueiras", station7, null); // 4 e 6
    	Node station4 = new Node("Guará", station5, null); // 3 e 5
    	Node station3 = new Node("Feira", station4, null); // 2 e 4
    	
    	Node station2 = new Node("Shopping", station3, null); // 1 e 3
    	Node station1 = new Node("Asa sul", station2, null); // 2
    	

//        Success
        BreadthFirstSearch bfs = new BreadthFirstSearch(station4, station9);
        
//        Fail
//        BreadthFirstSearch bfs = new BreadthFirstSearch(station5, station6);

        if(bfs.compute())
            System.out.print("Path Found!");
        else {
        	System.out.println("No path found \n:(");
        }
    }
    }