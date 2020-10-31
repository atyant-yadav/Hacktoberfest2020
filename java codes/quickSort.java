public class QSort
{
 
public static int partition(int a[],int l,int h)
{ 
int i=l+1 ,j=h,c=l,temp;
 
for(; i<=j ;)
{
 
while(i<=h && a[i]<a[c] ) 
i++; 
while(a[j]>a[c] && j>l)
j--;
 
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
else
break;
}
 
 
temp=a[c];
a[c]=a[j];
a[j]=temp;
return j;
}
 
public static void Sort(int a[],int l,int h)
{ 
if(l<h)
{
int m=partition(a,l,h);
Sort(a,l,m-1);
Sort(a,m+1,h);
 
} 
 
} 
 
public static void printarray(int a[])
{
for(int i=0; i < a.length; i++)
{
 
System.out.print(a[i]+" ");
}
 
}
public static void main(String[] args) 
{
int n, res,i;
Scanner s = new Scanner(System.in);
System.out.print("Enter number of elements in the array:");
n = s.nextInt();
int a[] = new int[n];
System.out.println("Enter "+n+" elements ");
for( i=0; i < n; i++)
{
a[i] = s.nextInt();
}
 
System.out.println( "elements in array ");
printarray(a);
Sort(a,0,n-1);
System.out.println( "\nelements after sorting");
printarray(a);
 
}
 
}