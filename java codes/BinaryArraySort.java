import java.io.*;
class BinaryArraySort
{
void sort(int arr[])
{
int i,j,temp;
int arrnew[]=new int[arr.length];
j=-1;
for (i=0;i<arr.length;i++)
{
arrnew[i]=arr[i];
}
for (i=0;i<arrnew.length;i++)
{
if (arrnew[i]<1)
{
j++; 
temp=arrnew[j]; 
arrnew[j]=arrnew[i]; 
arrnew[i]=temp; 
}
}
System.out.println("\nThe sorted array is as follows: ");
for(i=0;i<arrnew.length;i++)
{
System.out.println(arrnew[i]);
}
}
public static void main(String args[]) throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int n;
System.out.println("\nEnter the number of elements in the binary array: ");
n=Integer.parseInt(br.readLine());
int arr[]=new int[n];
System.out.println("\nEnter the elements of the binary array (please enter only 0's or 1's): ");
int i;
for(i=0;i<n;i++)
{
arr[i]=Integer.parseInt(br.readLine());
}
BinaryArraySort ob=new BinaryArraySort();
ob.sort(arr);
}
}