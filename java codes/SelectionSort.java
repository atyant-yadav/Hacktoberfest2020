import java.util.Scanner;  
  
public class SelectionSort 
{  
   public static void main(String args[])  
   {  
       int count, i, j, temp;  
       Scanner input = new Scanner(System.in);  
         
       System.out.print("Enter number of elements in Array: ");  
       count = input.nextInt();  
       int num[] = new int[count]; 
         
       System.out.print("Enter " + count + " Array Elements : ");  
       for(i=0; i<count; i++)  
       {  
           num[i] = input.nextInt();  
       }  
         
       System.out.print("Sorting Array using Selection Sort Algorithm..\n");  
       for(i=0; i<count; i++)  
       {  
           for(j=i+1; j<count; j++)  
           {  
               if(num[i] > num[j])  
               {  
                   temp = num[i];  
                   num[i] = arr[j];  
                   num[j] = temp;  
               }  
           }  
       }  
         
       System.out.print("Array after Sorting:\n");  
       for(i=0; i<count; i++)  
       {  
           System.out.print(num[i]+ "  ");  
       }  
   }  
}  
