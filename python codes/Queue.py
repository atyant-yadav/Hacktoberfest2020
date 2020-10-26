class Queue:
    def __init__(self):
        self.items = []

    def add_item(self, item):
        return self.items.insert(0, item)

    def remove_item(self):
        if self.is_empty():
            return print("Queue is Empty")
        return self.items.pop()

    def is_empty(self):
        return self.items == []

    def length(self):
        return len(self.items)

    def peek(self):
        if self.is_empty():
            return print("Queue is Empty")
        return self.items[-1]


def main():
    queue = Queue()
    print("Type Your Name : ")
    name = input()
    print("Welcome " + name)
    print("Choose your option")
    while True:
        print(" 1. Add Item \n 2. Remove Item \n 3. Length of Queue \n 4. Next Remove Item \n 5. Show Queue")
        print("________________________\n________________________")
        choice = input()
        if choice == "1":
            print("Enter Element (Any Data Type)")
            x = input()
            queue.add_item(x)
            print("*********************\n*********************")
        elif choice == "2":
            queue.remove_item()
        elif choice == "3":
            print('Length of the Queue is in Below')
            print(queue.length())
            print("*********************\n*********************")
        elif choice == "4":
            print("Next Remove Item is in below")
            print(queue.peek())
            print("*********************\n*********************")
        elif choice == "5":
            print(queue.items)
            print("*********************\n*********************")


main()
