
class AreaCalc
{
    static void area(float x)
    {
        System.out.println("Area of Square: "+ Math.pow(x, 2) +"sq units");
    }
    static void area(float x, float y)
    {
        System.out.println("Area of Rectangle :"+ x*y +"sq units");
    }
    static void area(double x)
    {
        double z = 3.14*x*x;
        System.out.println("Area of Circle :"+ z +"sq units");
    }
}
public class AreaCal {
public static void main(String[] args) {
    System.out.println("\n");
    AreaCalc.area(2);
    AreaCalc.area(5, 4);
    AreaCalc.area(5.4);
    System.out.println("\n");
}
}