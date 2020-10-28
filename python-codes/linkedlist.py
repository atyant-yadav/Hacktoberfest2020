class Node:
    
    def __init__(self, data,next=None):
        self.data= data
        self.next=next

class linkedlist:

    def __init__(self):
        self.head=None

    def insert(self, data):
        newNode = Node(data)
        
        if (self.head):
            currentNode = self.head
            while(currentNode.next):
                currentNode = currentNode.next
            currentNode.next = newNode
        else:
            self.head = newNode

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
            print(currentNode.data)
            currentNode = currentNode.next
        



