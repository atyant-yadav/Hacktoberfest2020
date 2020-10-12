class CircularQueue():

    # constructor
    def __init__(self, size): # initializing the class
        self.size = size

        # initializing queue with none
        self.queue = [None for i in range(size)]
        self.front = self.rear = -1

    def enqueue(self, data):

        # condition if queue is full
        if (self.rear + 1) % self.size == self.front:
            print(" Queue is Full\n")

        # condition for empty queue
        elif self.front == -1:
            print('{} added to the queue'.format(data))
            self.front = 0
            self.rear = 0
            self.queue[self.rear] = data
        else:
            print('{} added to the queue'.format(data))
            # next position of rear
            self.rear = (self.rear + 1) % self.size
            self.queue[self.rear] = data

    def dequeue(self):
        if self.front == -1: # codition for empty queue
            print ("Queue is Empty\n")

        # condition for only one element
        elif self.front == self.rear:
            temp=self.queue[self.front]
            self.front = -1
            self.rear = -1
            return temp
        else:
            temp = self.queue[self.front]
            self.front = (self.front + 1) % self.size
            return temp

    def display(self):

        # condition for empty queue
        if self.front == -1:
            print ("Queue is Empty")

        elif self.rear >= self.front:
            print("Elements in the  queue are:",
                                              end = " ")
            for i in range(self.front, self.rear + 1):
                print(self.queue[i], end = " ")
            print ()

        else:
            print ("Elements in  Queue are:",
                                           end = " ")
            for i in range(self.front, self.size):
                print(self.queue[i], end = " ")
            for i in range(0, self.rear + 1):
                print(self.queue[i], end = " ")
            print ()

        if ((self.rear + 1) % self.size == self.front):
            print("Queue is Full")

# Driver Code
ob = CircularQueue(10)
ob.enqueue(10)
ob.enqueue(20)
ob.enqueue(30)
ob.enqueue(50)
ob.display()
print ("Deleted value = ", ob.dequeue())
print ("Deleted value = ", ob.dequeue())
ob.display()
ob.enqueue(90)
ob.enqueue(30)
ob.enqueue(88)
ob.display() 