package Searching;

import java.util.*;

class Binary_Search
{
    int size;
    int a[];
    int search;
    
    public Binary_Search(int n)
    {
        size=n;
        a=new int[size];
    }
    public void input()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the elements of the array:");
        for(int i=0;i<size;i++)
        a[i]=in.nextInt();
        
        System.out.println("Enter the search element:");
        search=in.nextInt();
    }
    public int search()
    {
        int i=0;
        int j=a.length-1;
        int z=(int)(i+j)/2;
        while(i<=j)
        {
            z=(int)(i+j)/2;
            if(a[z]==search)
            {
                return (z+1);
            }
            else if(a[z]<search)
            i=z+1;
            else
            j=z-1;
        }
        return -1;
    }
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        
        System.out.println("Enter the size of the array:");
        int n=in.nextInt();
        
        Binary_Search ob=new Binary_Search(n);
        ob.input();
        int index=ob.search();
        System.out.println(index!=-1?"Search element found at "+index+" index":"Search element not found");
        
    }
}