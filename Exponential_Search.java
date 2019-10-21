package Searching;

import java.util.Arrays;
import java.util.Scanner;

public class Exponential_Search {

	public static int binarySearch(int[] arr, int startIndex, int endIndex, int number){
		return Arrays.binarySearch(arr, startIndex, endIndex, number);
	}

	public static int exponentialSearch(int[] arr, int number){
		int result = -1;
		if(arr[0] == number){
			return 0;
		}
		int i = 1;
		while(i < arr.length && arr[i] <= number){
			i *= 2;
		}
		// calling binary search for the found range
		result = binarySearch(arr, i/2, Math.min(i, arr.length), number);
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the number of elements in the array");
		int numberOfElements = s.nextInt();
		int[] arr = new int[numberOfElements];
		System.out.println("Enter the elements of the array in ascending and sorted order");
		for(int i = 0;i<arr.length;i++){
			arr[i] = s.nextInt();
		}
		System.out.println("Enter the element you want to search");
		int number = s.nextInt();
		int result = exponentialSearch(arr, number);
		if(result < 0){
			System.out.println("Element Not Found");
		}
		else{
			System.out.println("Element Found at index : " + result);
		}
	}

}
