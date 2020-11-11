import java.util.Scanner;
class Floydtriangle
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Input the limit");
        int n=sc.nextInt();
        int c=1;
        int y=c;
        for(int x=1;x<=n;x++)
        {
            System.out.print(x+" ");
            if(c==y)
            {
                System.out.println();
                c=0;
                y++;
            }
            c++;
        }
    }
}
