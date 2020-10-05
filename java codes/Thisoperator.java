class Thisoperator
{
 int a; 
 int b;

  void setdata(int a , int b)
   {
    this.a = a;
    this.b = b;
   }
  
   void showdata()
     {
    	 System.out.println("value of A ="+a);
    	 System.out.println("value of B ="+b);
     }
 
public static void main(String[] args)
{
Thisoperator c = new Thisoperator();
c.setdata(3,4);
c.showdata();
}

}