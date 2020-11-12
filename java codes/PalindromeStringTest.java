import java.io.*;
import java.util.*;

public class Solution {

//Given a String A (with scanner input), print Yes if it is a palindrome, print No if not.

static boolean isPalindrome(String str) 
    { int i = 0, j = str.length() - 1;  
        while (i < j) { 
            if (str.charAt(i) != str.charAt(j)) 
                return false;  
            i++; 
            j--; 
        } 
        return true; 
    } 

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        sc.close();

        //Is it a palindrome?
        if (isPalindrome(A)) {
            System.out.print("Yes"); 
       } else {
            System.out.print("No"); }
    } 
} 
