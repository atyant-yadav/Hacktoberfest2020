import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * java implementation of bredth first search
 *
 * first imput is the number of times you will do a BFS simulation (how many queries you are going to make)
 * then you input n and m
 * n -> the number of nodes that the newly generated graph should have
 * m -> how many edges (connections) that graph is going to have
 * for every edge you need to specify TWO nodes that are connected by it
 * lastly input which node the BFS should start from
 *
 * The goal of the BFS is to see if all nodes are reachable from the start node and to use the minimal distance between them
 */

public class BFS {

    private static class Graph {
        private Node[] nodes;

        private Node getNode(int number) {
            for(Node i : nodes) {
                if(i.index == number)
                    return  i;
            }
            return null;
        }

        //make an edge in graph
        private void addConnections(int index1, int index2) {
            Node node1 = getNode(index1);
            Node node2 = getNode(index2);

            if(node1 != node2 && node1 != null && node2 != null) {
                node1.connections.add(node2);
                node2.connections.add(node1);
            }
        }

        //create n nodes in graph
        private void createNodes(int n) {
            nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                Node node = new Node(i + 1);
                nodes[i] = node;
            }
        }

        //starts BFS from a selected node 's'
        public void doBFS(int sIndex) {
            Node s = getNode(sIndex);
            Queue<Node> queue = new LinkedList<>();
            s.visited = true;
            s.distanceToS = 0;
            /*if(s.connections.isEmpty()) {
                printBFS();
            }*/

            walkThrough(s, queue, 6);
        }

        //walk through graph and calculate min distances to s
        private void walkThrough(Node current, Queue<Node> q, int distance) {
            for(Node i : current.connections) {
                if(!i.visited) {
                    i.visited = true;
                    q.add(i);
                    if (i.distanceToS > distance) {
                        i.distanceToS = distance;
                    }
                }
            }
            Node next = q.peek();
            if (next == null) {
                printBFS();
            } else {
                q.poll();
                distance = next.distanceToS + 6;
                walkThrough(next, q, distance);
            }
        }

        //prints results
        private void printBFS() {
            for (Node i : nodes) {
                if(i.distanceToS == Integer.MAX_VALUE) {
                    System.out.print(-1 + " ");
                } else if (i.distanceToS == 0) {
                    continue;
                } else {
                    System.out.print(i.distanceToS + " ");
                }
            }
            System.out.println();
        }
    }

    private static class Node {
        private int index;
        private LinkedList<Node> connections;
        private boolean visited;
        private int distanceToS;

        public Node(int index) {
            this.index = index;
            connections = new LinkedList<>();
            visited = false;
            distanceToS = Integer.MAX_VALUE;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int queries = sc.nextInt();

        Graph graph = new Graph();

        for (int i = 0; i < queries; i++) {
            int n = sc.nextInt();
            graph.createNodes(n);
            int m = sc.nextInt();
            for (int j = 0; j < m; j++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                graph.addConnections(u, v);
            }
            int sIndex = sc.nextInt();
            graph.doBFS(sIndex);
        }

        sc.close();
    }

}
