using System;


public delegate void PriceChangedEventHandler ();
class Product {

  public event PriceChangedEventHandler PriceChanged;
  private decimal price;
  public decimal Price
  {
    get {
      return price;
    }
    set
    {
      price = value;
      if (PriceChanged!=null)
      {
        changeDetected();
      }
    }
  }
  public string Name;
  
  public string Url;

  public Product (string n, string u, decimal p )
  {
    Price = p;
    Name = n;
  	Url=u;
  }

  public void changeDetected()
  {
    Console.WriteLine("Changed to{0}", Price);
  }


}
class MainClass
{
    public static void Main (string[] args) {
    Product p = new Product ("anshita", "dsd", 12);
    p.PriceChanged+=p.changeDetected;
    Console.WriteLine(p.Name);
    p.Price = 20;
  }
}