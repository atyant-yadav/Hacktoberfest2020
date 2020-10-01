
public class BinarySearch {

		// Recursive Binary Search by JAVA
	public static void main(String args[]) 
	{ 
		BinarySearch ob = new BinarySearch(); 
		int arr[] = { 20, 13, 4, 11, 40 }; 
		int n = arr.length; 
		int x = 11; 
		int result = ob.binarySearch(arr, 0, n - 1, x); 
		if (result == -1) 
			System.out.println("Element not present"); 
		else
			System.out.println("Element found at index " + result+".");
			System.out.println("Element is at " + (result+1)+" position.");
	} 
		
		int binarySearch(int arr[], int l, int r, int x) 
		{ 
			if (r >= l) { 
				int mid = l + (r - l) / 2; 

				// If element is present at the middle itself 
				if (arr[mid] == x) 
					return mid; 

				// If element is smaller than mid, then it can only be present in left subarray 
				if (arr[mid] > x) 
					return binarySearch(arr, l, mid - 1, x); 

				// Else the element can only be present in right subarray 
				return binarySearch(arr, mid + 1, r, x); 
			} 

			// We reach here when element is not present in array 
			return -1; 
		} 

		
	} 
	


