import java.util.ArrayList;

/**
 * A classe Node representa uma estação
 * cada estação tem uma string representando
 * o nome da estação, e um ArrayList que
 * serve para armazenar todos os Nodes filhos
 * instanciados
 */
public class Node {

    //	  É um identificador único do Node
    public String stationName;
    
    //    Os Nodes filhos os quais este node está diretamente conectado.
    Node leftChild;
    Node rightChild;

    public Node(String stationName, Node firstChild, Node secondChild){
        this.stationName = stationName;
        this.leftChild = firstChild;
        this.rightChild = secondChild;
    }

    public ArrayList<Node> getChildren(){
    //  Um ArrayList contendo os Nodes filhos desde Node
        ArrayList<Node> childNodes = new ArrayList<>();
    	
        if(this.leftChild != null)
        {
            childNodes.add(leftChild);
        }
        if(this.rightChild != null) {
            childNodes.add(rightChild);
        }
        return childNodes;
    }

    //    Um método auxiliar que nos  
    //    permite remover qualquer Node filho
    //	  da lista de um Node referenciado
    public boolean removeChild(Node n){
        return false;
    }
    
    @Override
    public String toString() {
    	return this.stationName;
    }

}