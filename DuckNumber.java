// Java Program to check whether a 
// number is Duck Number or not. 

import java.io.*; 
class GFG { 

	// Function to check whether 
	// the given number is duck number or not. 
	static boolean check_duck(String num) 
	{ 
		// Ignore leading 0s 
		int i = 0, n = num.length(); 
		while (i < n && num.charAt(i) == '0') 
			i++; 

		// Check remaining digits 
		while (i < n) { 
			if (num.charAt(i) == '0') 
				return true; 
			i++; 
		} 

		return false; 
	} 

	// Driver Method 
	public static void main(String args[]) throws IOException 
	{ 
		String num = "1023"; 
		if (check_duck(num)) 
			System.out.println("It is a duck number"); 
		else
			System.out.println("It is not a duck number"); 
	} 
} 
