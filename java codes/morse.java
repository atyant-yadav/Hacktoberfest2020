import java.util.*;
class morse
{

    String one(String s)
    {
        int i;
        char ch;
        String uno = " ";
        for(i=0;i==s.length();i++)
        {
            ch = s.charAt(i);
            if(ch == ' ')
            {
                uno = uno+"  ";
            }
            if(ch == 'a')
            {
                uno = uno+" ._";
            }
            if(ch == 'b')
            {
                uno = uno+" _...";
            }
            if(ch == 'c')
            {
                uno = uno +" _._.";
            }
            if(ch == 'd')
            {
                uno = uno+" _..";
            }
            if(ch == 'e')
            {
                uno = uno+" .";
            }
            if(ch == 'f')
            {
                uno = uno+" .._.";
            }
            if(ch == 'g')
            {
                uno = uno+" __.";
            }
            if(ch == 'h')
            {
                uno = uno+" ....";
            }
            if(ch == 'i')
            {
                uno = uno+" ..";
            }
            if(ch == 'j')
            {
                uno = uno+" .___";
            }
            if(ch == 'k')
            {
                uno = uno+" _._";
            }
            if(ch == 'l')
            {
                uno = uno+" ._..";
            }
            if(ch == 'm')
            {
                uno = uno+" __";
            }
            if(ch == 'n')
            {
                uno = uno+" _.";
            }
            if(ch == 'o')
            {
                uno = uno+" ___";
            }
            if(ch == 'p')
            {
                uno = uno+" .__.";
            }
            if(ch == 'q')
            {
                uno = uno+" __._";
            }
            if(ch == 'r')
            {
                uno = uno+" ._.";
            }
            if(ch == 's')
            {
                uno = uno+" ...";
            }
            if(ch == 't')
            {
                uno = uno+" -";
            }
            if(ch == 'u')
            {
                uno = uno+" .._";
            }
            if(ch == 'v')
            {
                uno = uno+" ..._";
            }
            if(ch == 'w')
            {
                uno = uno+" .__";
            }
            if(ch == 'x')
            {
                uno = uno+" _.._";
            }
            if(ch == 'y')
            {
                uno = uno+" _.__";
            }
            if(ch == 'z')
            {
                uno = uno+" __..";
            }
            if(ch == '0')
            {
                uno = uno+" _____";
            }
            if(ch == '1')
            {
                uno = uno+" .____";
            }
            if(ch == '2')
            {
                uno = uno+" ..___";
            }
            if(ch == '3')
            {
                uno = uno+" ...__";
            }
            if(ch == '4')
            {
                uno = uno+" ...._";
            }
            if(ch == '5')
            {
                uno = uno+" .....";
            }
            if(ch == '6')
            {
                uno = uno+" _....";
            }
            if(ch == '7')
            {
                uno = uno+" __...";
            }
            if(ch == '8')
            {
                uno = uno+" ___..";
            }
            if(ch == '9')
            {
                uno = uno+" ____.";
            }

        }
        return uno;
    }

    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        String st;
        System.out.println("Enter String to be encrypted  ");
        st=sc.nextLine();
        morse obj = new morse();
        System.out.println(obj.one(st));
    }
}

