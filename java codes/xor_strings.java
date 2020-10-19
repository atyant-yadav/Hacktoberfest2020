import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class xor_strings {

    public static void main(String args[])
    {
Scanner sc=new Scanner(System.in);
String s=sc.next();
String t=sc.next();
String word="";
for(int i=0;i<s.length();i++)
{
    if(s.charAt(i)!=t.charAt(i))
    word=word+'1';
    else
    word=word+'0';
}
System.out.println(word);
}
}
