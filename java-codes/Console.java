public class Console
{
    public static void main(String[] args) 
    {        
        
        String name = System.console().readLine();
        
        System.out.println(name);
    }
}