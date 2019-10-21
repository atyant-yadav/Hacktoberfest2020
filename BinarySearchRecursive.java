public class binarysearch {
	public static int binarySearch(int key, int[] arr, int start, int end){
		
		int middle = (start + end)/2;
		
		if(end < start){
			 return -1;
		} 
		
		if (key < arr[middle]){
			return binarySearch(key, arr, start, middle - 1);
		}
		
		if (key > arr[middle]){
			return binarySearch(key, arr, middle + 1, end);
		}
		
		if (key == arr[middle]){
			return middle;
		}
		
		return -1;
	}
	public static void main(String args[])
	{
		 int arr[] = { 2, 3, 4, 10, 40 }; 
		 
	        int n = arr.length; 
	        int x = 10; 
	        int result = binarySearch(x, arr,0,n-1); 
	        if (result == -1) 
	            System.out.println("Element not present"); 
	        else
	            System.out.println("Element found at index " + result); 
	    } 
	}
