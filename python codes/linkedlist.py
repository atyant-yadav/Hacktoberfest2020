# create the node
class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

# create the LL
class linkedlist:
    def __init__(self):
        self.head = None
    
# insertion in the LL at beginning
    def insert_beg(self, data):
        self.head = Node(data=data, next=self.head)

# insertion at the end
    def insert_end(self, data):
        if not self.head:
            self.head = Node(data=data)
            return
        
        currentNode = self.head
        while(currentNode.next):
            currentNode = currentNode.next
        currentNode.next = Node(data=data)

# insertion at node after a certain node
    def insert_any(self, cer_data, data):
        if not self.head:
            return
        else:
            currentNode = self.head
            while(currentNode.data!=cer_data):
                currentNode = currentNode.next
            currentNode.next = Node(data=data, next=currentNode.next)

# deletion
    def delete(self, data):
        currentNode = self.head
        while(currentNode):
            if(currentNode.data==data):
                self.head=currentNode.next
                print("Node deleted")
                return
            
            prev = currentNode
            currentNode = currentNode.next
            if (currentNode.data == data):
                prev.next = currentNode.next
                print("Node deleted")
                return
            else:
                print("Node not found")

    def printLL(self):
        currentNode = self.head
        while(currentNode):
            print(currentNode.data,  end =" => ")
            currentNode = currentNode.next

# EXAMPLE
s = linkedlist()

s.insert_beg(5)
s.insert_end(4)
s.insert_any(4,1)
s.insert_beg(0)

s.printLL()

# OUTPUT : 0 => 5 => 4 => 1 => 
