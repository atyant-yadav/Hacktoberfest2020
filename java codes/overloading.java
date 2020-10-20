import java.util.*;

class Overloading{
    public int overload(int a,int b)
    {
        return (a+b);
    }
    public String overload(String a, String b){
        return(a+b);
    }
    public static void main(String[] args) {
        Overloading over=new Overloading();
        System.out.println(over.overload(5,7));
        System.out.println(over.overload("Sim","Ran"));
    }
}