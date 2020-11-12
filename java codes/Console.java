public class Console
{
    public static void main(String[] args) 
    {        
        
        String name = System.console().readLine();
        
        System.out.println(name);
        
        String name2= System.console().nextLine();
        System.out.println(name2);
    }
}
