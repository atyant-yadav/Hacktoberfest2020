public class MyLinkedlist<E> {
//Creating Node class that will consist a data part and initially the next pointer is pointing to null.This means there is a single node.
  static class Node<E> {
		E data;
		Node<E> next;
		public Node(E data)
		{
			this.data=data;
			next = null;
		}
	}
  
  //Creating an instance of class Node
	Node<E> head;
  
  //Add function will be used to add nodes to the linkedlist.
	public void add(E data)
	{
		Node<E> toAdd = new Node<E>(data);
		Node<E> temp=head;
		if(isEmpty())
		{
			head=toAdd;
			return;
		}	
		while(temp.next!=null)
			{temp=temp.next;
		}
		temp.next=toAdd;
	}
  
//isEmpty() will check whether the linkedlist is empty or not.It will return boolean value.
	public boolean isEmpty()
	{
		return head==null;
	}
	public void print()
	{
		Node<E> temp=head;
		
		while(temp!=null)
		{
		 System.out.print(temp.data+" ");
		 temp=temp.next;
		}
		System.out.println();
}
  //removelast() will return the last node of the linkedlist
	public E removelast() throws Exception
	{
		Node<E> temp=head;
		if(isEmpty())
		{
			throw new Exception("cannot remove last element from empty list");
		}
		if(temp.next==null)
		{
		Node<E> toremove =temp;
		head=null;
		return  toremove.data;
		}
		while(temp.next.next!=null)
		{
		 temp=temp.next;
		}
		Node<E> toremove =temp.next;
		temp.next=null;
		return  toremove.data;
}
  //getlast() will return the data part of the last node
	public E getlast() throws Exception
	{
		Node<E> temp=head;
		if(isEmpty())
		{
			throw new Exception("cannot remove last element from empty list");
		}
		while(temp.next!=null)
		{
			temp=temp.next;
		}
		return temp.data;
	}
}

public class Test {

	public static void main(String[] args) throws Exception {
    //  Making an instance of Mylinkedlist class.
		MyLinkedlist<Integer> ll=new MyLinkedlist<Integer>();
    //Adding elements to the linkedlist
		ll.add(15);
		ll.add(20);
		ll.add(25);
    
		System.out.println("original linkedlist");
    //Printing the elements of the linkedlist
		ll.print();
    
    //Removing Last element of the  linkedlist
		ll.removelast();
    
		System.out.println("updated linkedlist");
		ll.print();
    //getlast will return the last element of the linkedlist
		System.out.println("last element :"+ll.getlast());
		System.out.println(ll.isEmpty()+" returning false because linkedlist is not empty");

	}

}
