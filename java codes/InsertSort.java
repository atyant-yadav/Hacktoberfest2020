public class InsertSort {
  public static void main (String [] args) {
   int n=args.length;
   int[] array = new int[n];
   for(int i=0;i<n;i++)
   {
     array[i]=Integer.parseInt(args[i]);
   }
   int temp;
   for (int i = 1; i < array.length; i++) {
    for (int j = i; j > 0; j--) {
     if (array[j] < array [j - 1]) {
      temp = array[j];
      array[j] = array[j - 1];
      array[j - 1] = temp;
     }
    }
   }
   for (int i = 0; i < array.length; i++) {
     System.out.print(array[i]+" ");
   }
  }
}