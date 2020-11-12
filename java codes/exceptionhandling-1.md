QUES- CHECKING THE REGISTRATION NUMBER AND MOBILE NUMBER EXCEPTION

CODE-

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

public class SaurabhSingh19BCI0184x {

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
    try
    {
    System.out.println("Enter your Regestration  Number:");
    String regno = sc.next();
    System.out.println("Enter your Mobile  Number:");
    String phno = sc.next();
    char[] chregno = regno.toCharArray();
    char[] chphn = phno.toCharArray();
    
    if(chregno.length!=9)
    {
		throw new IllegalArgumentException();}

    if(chphn.length!=10)
    {
        throw new IllegalArgumentException();
    }
    for(int i=0;i<chphn.length;i++)
    {
        if(!Character.isDigit(chphn[i]))
        {
            throw new NumberFormatException();
        }
    }
    for(int i=0;i<chregno.length;i++)
    {
        if(!Character.isDigit(chregno[i]) && !Character.isLetter(chregno[i]))
        {
            throw new NoSuchElementException();
        }
    }
    
    System.out.println("Valid");
}

    
    catch(NumberFormatException e)
    {
         System.out.println("Invalid No 1");
         throw new NumberFormatException("Mobile Number cannot contain any character other than a digit");
         
    }
    
    catch(IllegalArgumentException e)
    {
         System.out.println("Invalid No 2");
         throw new IllegalArgumentException("Input does not contain specified length of data");
    }
    
    catch(NoSuchElementException e)
    {
        System.out.println("Invalid No 3");
        throw new NoSuchElementException("Registration Number cannot contain any character other than digits and alphabets");
    }
    
    }
    
}
