import java.util.*;
class anagram{
	public static void main(String[] args){
		Scanner sc= new Scanner(System.in);
		String s=sc.nextLine();
		String s1=sc.nextLine();
		if(s.length()!=s1.length()){
			System.out.println(s1+" and "+s2+" are Not Anagrams");
			return;
		}
		char[] sarr=s.toCharArray();
		char[] s1arr=s1.toCharArray();
		Arrays.sort(sarr);
		Arrays.sort(s1arr);
		boolean b=false;
		for(int i=0;i<s1arr.length;i++){
			if(sarr[i]!=s1arr[i]){
				b=true;
				System.out.println(s1+" and "+s2+" are Not Anagrams");
				return;
			}
		}
		if(b==false){
			System.out.println(s1+" and "+s2+" are Anagrams");
		}
	}
}
