package Searching;

import java.util.*;

class Linear_Search
{
    int size;
    int a[];
    int search;
    
    public Linear_Search(int n)
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
        for(int i=0;i<size;i++)
        {
            if(a[i]==search)
            return i;
        }
        return -1;
    }
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        
        System.out.println("Enter the size of the array:");
        int n=in.nextInt();
        
        Linear_Search ob=new Linear_Search(n);
        ob.input();
        int index=ob.search();
        System.out.println(index!=-1?"Search element found at "+index+" index":"Search element not found");
        
    }
}