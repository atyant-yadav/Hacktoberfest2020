/*Write a program which does the following:
1)deletes all the vowels,
2)inserts a character "." before each consonant,
3)replaces all uppercase consonants with corresponding lowercase ones.*/
import java.util.*;
public class s5
{
    public static void main()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the String");
        String s=in.nextLine().toLowerCase();String st="";
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(s.charAt(i)!='a'&&s.charAt(i)!='e'&&s.charAt(i)!='i'&&s.charAt(i)!='o'&&s.charAt(i)!='u')
            {
                st=st+ch;
            }
        }
        s=st;st="";
        for(int i=0;i<s.length();i++)
        {if(s.charAt(i)!=' ')
            st=st+"."+s.charAt(i);
            else
            st=st+s.charAt(i);
        }
        System.out.print(st);
    }}
        