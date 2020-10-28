

class Box
{
    double width;
    double height;
    double depth;
}


public class Assign
{
     public static void main(String[] args) 
    {
        
        Box b1 = new Box();
        
       
        Box b2 = b1;
        
       
        System.out.println(b1.height);
        System.out.println(b2.height);
        
       
        b2.height = 20;
        
       
       
        System.out.println(b1.height);
        System.out.println(b2.height);
    }
    
}
