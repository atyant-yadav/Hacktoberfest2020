package collectionFrameworkList;

import java.util.LinkedList;

public class linkedListCB {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		@SuppressWarnings({ "unchecked", "rawtypes" })
		LinkedList<Integer> list = new LinkedList();
		list.add(1);
		list.add(2);
		list.addFirst (3);
		list.add(1,6);
		//alternate method
		list.add(2,3);
		System.out.println(list.contains(3));
		@SuppressWarnings("unchecked")
		LinkedList<Integer> list1=(LinkedList<Integer>) list.clone();
		System.out.println(list1);
		System.out.println(list.size());
		System.out.println(list.getFirst());
		System.out.println(list1.getLast());
		list1.addLast(45);
		list.addFirst(22);
		list.addFirst(3);
		System.out.println(list);
		//list.removeFirstOccurrence(3);
		System.out.println(list);
		//list.removeLastOccurrence(3);
		System.out.println(list);
		System.out.println(list.pollLast());
		list.remove(3);
		System.out.println(list);
	}

}
