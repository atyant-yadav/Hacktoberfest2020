import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Stack;

class DFSgraph{
    static Scanner sc;
    public static void main(String args[]){

        try{
            File file = new File("C:\\Users\\Tanisha\\Desktop\\dfs_input.txt");
            sc = new Scanner(file);           
        }
        catch(Exception e){
            System.out.println("Error");
            System.out.println(e.getMessage());
        }

            String initialInfo;
            if(sc.hasNextLine())
            initialInfo = sc.next();
            else initialInfo = "";
            String[] arr = initialInfo.split(",");
            int n = Integer.parseInt(arr[0]);

            ArrayList<Integer>[] graph = new ArrayList[n];
            for(int i=0; i<n; i++) {
                graph[i] = new ArrayList<>();
            }
            sc.next();
            if(arr[1].equals("u")){
                while (sc.hasNext()){
                    String s = sc.next();
                    graph[s.charAt(0)-97].add(s.charAt(2)-97);
                    graph[s.charAt(2)-97].add(s.charAt(0)-97);
                }
            }
            else if(arr[1].equals("d")){
                while (sc.hasNext()){
                    String s = sc.next();
                    graph[((int)s.charAt(0)-97)].add(s.charAt(2)-97);
                }
            }

        try{
            PrintStream ps = new PrintStream(new File("out_dfs.txt"));
            PrintStream console = System.out; 
            System.setOut(ps);
            dfs(graph);
            //System.out.println(k.substring(k.length()-1));
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
    
    public static void dfs(ArrayList<Integer>[] graph){
        Stack<Integer> st = new Stack<>();
        int count = 0;
        boolean[] vis = new boolean[graph.length];
        st.push(0);
        
        while(!st.isEmpty()){
            int curr_vtx = st.pop();
            vis[curr_vtx]=true;
            if(count==graph.length){
                System.out.print(((char)(curr_vtx+'a'))+" ");
                return;
            }
            System.out.print(((char)(curr_vtx+'a')+",")+" ");
            // for(int n : graph[curr_vtx]){
            //     if(!vis[n]){
            //         st.push(n);
            //         vis[n] = true;
            //     }
            // }
            for(int i=graph[curr_vtx].size()-1; i>=0; i--){
                int n = graph[curr_vtx].get(i);
                if(!vis[n]){
                    st.push(n);
                    vis[n] = true;
                    count++;
                }
            }
        }
       
    }

}