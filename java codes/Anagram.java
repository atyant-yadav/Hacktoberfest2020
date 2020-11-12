import java.util.Arrays;
import java.util.Scanner;

public class Anagram {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter first string: ");
		String str1 = sc.nextLine();
		System.out.println("Enter second string: ");
		String str2 = sc.nextLine();
		
		boolean anagram = isAnagram(str1, str2);
		
		if(anagram)
		{
			System.out.println("The two strings are anagram of each other");
		}
		else
		{
			System.out.println("The two strings are not anagram of each other");
		}
	
	}
	
	public static String sortString(String inputString) {
		
		char[] charArray = inputString.toCharArray();
		
		Arrays.sort(charArray);
		
		return new String(charArray);
	}
	
	public static boolean isAnagram(String str1, String str2) {
		
		if(str1.length() != str2.length())
		{
			return false;
		}
		else
		{
			String s1 = sortString(str1);
			String s2 = sortString(str2);
			
			if(s1.equals(s2))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
	}

}
