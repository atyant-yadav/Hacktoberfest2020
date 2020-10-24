import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class TopologicalSort
{
    static boolean[] visited;
    static ArrayList<Integer> vertices = new ArrayList<>();
    static int n;
    private static void topologicalSort(ArrayList<Integer>[] adj)
    {
        for (int i = 0; i < n; i++)
        {
            if(!visited[i])
                explore(i, adj);
        }

    }
    private static void explore(int vertex, ArrayList<Integer>[] adj)
    {
        visited[vertex] = true;
        for (Integer neighbour : adj[vertex])
        {
            if(!visited[neighbour])
            {
                explore(neighbour, adj);
            }
        }
        vertices.add(vertex);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int m = scanner.nextInt();
        visited = new boolean[n];
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            adj[x - 1].add(y - 1);
        }
        topologicalSort(adj);
        Collections.reverse(vertices);
        for (Integer i : vertices)
        {
            System.out.print(i + 1 + " ");
        }

    }
}

