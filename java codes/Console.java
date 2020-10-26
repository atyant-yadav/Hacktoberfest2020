public class Console
{
    public static void main(String[] args) 
    {        
        
        String name = System.console().readLine();
        
        System.out.println(name);
        
        
        String name23 = System.console().next();
        
        System.out.println(name23);
        
        
        String name3 = System.console().nextLine();
        
        System.out.println(name3);
    }
}
