import java.util.*;

class Interpolation_Search
{
    int size;
    int a[];
    int search;
    
    public Interpolation_Search(int n)
    {
        size=n;
        a=new int[size];
    }
    public void input()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the elements of the array in ascending order or descending order:");
        for(int i=0;i<size;i++)
        a[i]=in.nextInt();
        
        System.out.println("Enter the search element:");
        search=in.nextInt();
    }
    public int search()
    {
        int l=0;
        int h=size-1;
        while(l<=h&&a[l]<=search&&a[h]>=search)
        {
            if(h==l) 
            {
                if(a[l]==search) return l;
                return -1;
            }
            
            int pos=l+(int)(((h-l)/(a[h]-a[l]))*(search-a[l]));
            
            if(a[pos]==search) return pos;
            if(a[pos]<search) l=pos+1;
            if(a[pos]>search) h=pos-1;
        }
        return -1;
    }
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        
        System.out.println("Enter the size of the array:");
        int n=in.nextInt();
        
        Interpolation_Search ob=new Interpolation_Search(n);
        ob.input();
        int index=ob.search();
        System.out.println(index!=-1?"Search element found at "+index+" index":"Search element not found");
        
    }
}
