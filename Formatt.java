import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;


class Formatt
{
  public static void main(String[] args) throws ParseException
{
  
  SimpleDateFormat ft = new SimpleDateFormat("dd-MM-yyyy");
  String str = ft.format(new Date());
  System.out.println("formatted date : " + str);

  str = "10/01/2000";
  ft  = new SimpleDateFormat("dd/MM/yyyy");
  Date date = ft.parse(str);

  System.out.println("parsed date = " + date);
}
}