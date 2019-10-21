package Searching;

import java.util.*;

class Jump_Search
{
    int size;
    int a[];
    int search;
    
    public Jump_Search(int n)
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
        int jump=(int)Math.floor(Math.sqrt(size));
        int prev=0;
        while(a[Math.min(jump,size)-1]<search)
        {
            prev=jump;
            jump+=(int)Math.floor(Math.sqrt(size));
            
            if(prev>=size) 
            return -1;
        }
        
        while(a[prev]<search)
        {
            prev++;
            if(prev==Math.min(jump,size))
            return -1;
        }
        
        if(a[prev]==search) 
        return prev;
        
        return -1;
    }
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        
        System.out.println("Enter the size of the array:");
        int n=in.nextInt();
        
        Jump_Search ob=new Jump_Search(n);
        ob.input();
        int index=ob.search();
        System.out.println(index!=-1?"Search element found at "+index+" index":"Search element not found");
        
    }
}