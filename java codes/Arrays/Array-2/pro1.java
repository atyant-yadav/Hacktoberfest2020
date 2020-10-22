import java.util.HashSet;

/*package whatever //do not write package name here */
class pro1 {
	public static void intersection(int[] array1, int[] array2) {
		HashSet<Integer> set = new HashSet(); 
		for (int i = 0; i < array1.length; i++) {
			set.add(array1[i]);
		}
		for (int i = 0; i < array2.length; i++) {
			if(set.contains(array2[i])) {
				System.out.println(array2[i]);
			}
		}
	}
	public static void union(int[] array1, int[] array2){
		HashSet<Integer> set = new HashSet(); 		// space complexity O(m+n)
		for (int i = 0; i < array1.length; i++) { // O(n)
			set.add(array1[i]);			// O(1) operation on set take constant time
		}
		for (int i = 0; i < array2.length; i++) { // O(m)
			set.add(array2[i]);
		}

		System.out.println(set);
	}
	public static void main(String[] args) {
		int[] array1 = {1,1,10,1,1,1,1,1,1,1};
		int[] array2 = {1,1,4,1,2};
		union(array1,array2);
		intersection(array1, array2);
	}
}














