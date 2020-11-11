def merge(head_a,head_b):
    front=head_a
    secd=front
    #code here
    temp=head_a
    while head_a!=None and head_b!=None:
        
        '''if head_b.data>head_a.data:
            temp=head_a
            head_a=head_a.next
            
        if head_a.data>head_b.data:
            temp.next=head_b
            temp=head_b
            head_b=head_b.next
            temp.next=head_a
        else:
            temp=head_a
            head_a=head_a.next
            head_b=head_b.next'''
        while secd!=None:
        	print(secd.data,end=" ")
        head_a=head_a.next
        #print()
    if head_a==None and head_b!=None:
            temp.next=head_b
    return front
#Initial Template for Python 3
# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            return
        curr_node = self.head
        while curr_node.next is not None:
            curr_node = curr_node.next
        curr_node.next = new_node
    # prints the elements of linked list starting with head
    def printList(self):
        if self.head is None:
            print(' ')
            return
        curr_node = self.head
        while curr_node:
            print(curr_node.data,end=" ")
            curr_node=curr_node.next
        print(' ')
if __name__ == '__main__':
    t=int(input())
    for cases in range(t):
        n,m = map(int, input().strip().split())
        a = LinkedList() # create a new linked list 'a'.
        b = LinkedList() # create a new linked list 'b'.
        nodes_a = list(map(int, input().strip().split()))
        nodes_b = list(map(int, input().strip().split()))
        for x in nodes_a:
            a.append(x)
        for x in nodes_b:
            b.append(x)
        a.head = merge(a.head,b.head)
        a.printList()

''' This is a function problem.You only need to complete the function given below '''
#User function Template for python3
'''
	Function to merge two sorted lists in one
	using constant space.
	
	Function Arguments: head_a and head_b (head reference of both the sorted lists)
	Return Type: head of the obtained list after merger.
	{
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	}
	Contributed By: Nagendra Jha
'''
