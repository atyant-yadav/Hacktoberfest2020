import java.util.*;  
public class Shell_Sort   
{  
static void shellsort(int[] arr, intnum)    
{    
int i, j, k, tmp;    
for (i = num / 2; i> 0; i = i / 2)    
{    
for (j = i; j<num; j++)    
{    
for(k = j - i; k>= 0; k = k - i)    
{    
if (arr[k+i] >= arr[k])    
break;    
else  
{    
tmp = arr[k];    
arr[k] = arr[k+i];    
arr[k+i] = tmp;    
}    
}    
}    
}    
}     
public static void main(String[] args)   
{    
Scanner sc = new Scanner(System.in);  
int arr[]= newint[30];    
intk,  num;    
System.out.println("Enter total no. of elements : ");      
num = sc.nextInt();  
for (k =  0 ; k<num; k++)    
{    
arr[k]=sc.nextInt();    
}    
shellsort(arr, num);    
System.out.println("\n Sorted array is: ");    
for (k = 0; k<num; k++)    
System.out.println(arr[k]);    
}    
}  
