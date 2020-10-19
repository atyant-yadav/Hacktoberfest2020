import java.util.*;
public class permut
{
    int n,d;
    int a[],max=0,min=0;
    Scanner sc = new Scanner(System.in);
    void input()
    {
        System.out.println("Enter A Number");
        n=sc.nextInt();
        d=0;
        int r=n;
        while(r>0)
        {
            r=r/10;
            d++;
        }
        a=new int[d];
    }

    void array()
    {

        int i,j,temp=0;
        for(i=0;i<d;i++)
        {
            a[i]=0;
        }
        int cp=n;
        for(i=0;i<d;i++)
        {
            a[i]=cp%10;
            cp=cp/10;
        }

        for( i=0; i < d; i++)
        {  
            for(j=1; j < (d-i); j++)
            {  
                if(a[j-1] < a[j])
                {  
                    //swap elements  
                    temp = a[j-1];  
                    a[j-1] = a[j];  
                    a[j] = temp;  
                }  

            }  
        }  
    }

    void limit()
    {
        int i,d1=d-1;
        for(i=0;i<d;i++)
        {
            max=(max*10)+a[i];
            d1=(d-1)-i;
            min=(min*10)+a[d1];
        }

    }

    void mute()
    {
        input();
        array();
        limit();
        int i,j,k,check=0;
       
        for(i=min;i<=max;i++)
        {
           check=comp(i);
           if(check==1)
           {
               System.out.println(i);
           }
        }
    }
   
    int comp(int x)
    {
        int y,z,i1,j1,temp1=0;
        int ar[]=new int[d];
        z=x;
        for(y=0;y<d;y++)
        {
            ar[y]=z%10;
            z=z/10;
        }
       
        for( i1=0; i1 < d; i1++)
        {  
            for(j1=1; j1 < (d-i1); j1++)
            {  
                if(ar[j1-1] < ar[j1])
                {  
                    //swap elements  
                    temp1 = ar[j1-1];  
                    ar[j1-1] = ar[j1];  
                    ar[j1] = temp1;  
                }  

            }  
        }  
       
       
        for( i1=0; i1 < d; i1++)
        {
            if(a[i1]!=ar[i1])
            return 0;
           
        }
        return 1;
    }
   
    public static void main()
    {
        permut ob = new permut();
        ob.mute();
    }
}