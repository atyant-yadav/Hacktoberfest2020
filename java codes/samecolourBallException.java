import java.lang.Math;
class SameColourBallException extends Exception
{
	SameColourBallException(int x)
{
System.out.println("Same colour ball was picked more than three time.");
}
}
public class ExceptionhandlingballsQ_2SAURABHSINGH {
public static void main(String[] args) {
int red=0,green=0,blue=0,yellow=0;
int pickn;
for(int i=0;i<10;i++)
{
pickn = (int) ((Math.random() * ((4 - 1) + 1)) + 1);
if(pickn==1)
	red++;
if(pickn==2)
	green++;
if(pickn==3)
	blue++;
if(pickn==4)
	yellow++;
try
{
if(red>3)
throw new SameColourBallException(0);
else if(green>3)
throw new SameColourBallException(0);
else if(blue>3)
throw new SameColourBallException(0);
else if(yellow>3)
throw new SameColourBallException(0);
}

catch(SameColourBallException exp)
{
System.out.println("Error Found!!!");
}
}
System.out.println("NO OF RED BALL PICKS ARE:   ");
System.out.println(red);
System.out.println("NO OF GREEN BALL PICKS ARE:   ");
System.out.println(green);
System.out.println("NO OF BLUE BALL PICKS ARE:   ");
System.out.println(blue);
System.out.println("NO OF YELLOW BALL PICKS ARE:   ");
System.out.println(yellow);
}
}
