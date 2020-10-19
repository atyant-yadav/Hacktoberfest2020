import java.util.*;
import java.math.*;

public class ExponentialSearch{
	public static void main(String... args){
		int arr[] = {2,4,6,8,10,12,18,30};
		int search = 12;
		//search item, 12
		int searchItem = 12;
		int index = exponentialBinarySearch(arr,arr.length,searchItem);
		System.out.println("Item found on index "+index);
	}

	
	static int exponentialBinarySearch(int array[], int arrayLength, searchItem){
		if(array[0] == searchItem)
		return 0;
		int i = 1;
		while(i<arrayLength && array[i] <=searchItem){
			i = i*2
		}
		return Arrays.binarySearch(array, (i / 2), Math.min(i, n), searchValue);
	}

}
