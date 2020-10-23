import java.util.*; 
import java.io.*; 
import java.lang.*; 

class Count
{ 
    public static void main(String args[]) throws IOException
    { 
        Scanner scan = new Scanner(System.in); 
        String item; 
        int u_count = 0 , l_count = 0 ,  s_count = 0 , b_count = 0 , d_count = 0; 
        System.out.println("Enter the string"); 
        item = scan.nextLine(); 
        char ch[] = item.toCharArray(); 
        for(int i = 0 ; i < item.length() ; i++)
        { 
            if(ch[i] >='A' && ch[i]<='Z')
            { 
                u_count++; 
            }
            else if(ch[i]>='a' && ch[i]<='z')
            {
                l_count++; 
            }
            else if(ch[i]=='\t' || ch[i]==' ')
            { 
                b_count++; 
            }
            else if(ch[i]>='0' && ch[i]<='9')
            { 
                d_count++; 
            }
            else 
            { 
                s_count++; 
            }
        }  
        System.out.println("No. of uppercase letters is: " + u_count + "\nNo. of lowercase letters is:" + l_count + "\nNo. of blank spaces is:" + b_count + "\nNo. of special characters is:" + s_count + "\nNo. of digits is:" + d_count); 
    }
}