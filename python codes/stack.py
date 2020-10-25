class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):

        return self.items.append(item)
        

    def pop(self):
        if self.is_empty():
            return print("Stack is Empty")
        return self.items.pop()
        

    def is_empty(self):
        return self.items == []

    def stack_length(self):
        return len(self.items)

    def peek(self):
        if self.is_empty():
            return print("Stack is Empty")
        return self.items[-1]
        


def main():
    stack = Stack()
    print("Type Your Name : ")
    name = input()
    print("Welcome " + name)
    print("Choose your option")
    while True:
        print(" 1. Push \n 2. Pop \n 3. Length \n 4. Top-Item \n 5. Show Stack")
        print("________________________\n________________________")
        choice = input()
        if choice == "1":
            print("Enter Element (Any Data Type)")
            x = input()
            stack.push(x)
            print("*********************\n*********************")
        elif choice == "2":
            stack.pop()
        elif choice == "3":
            print('Length of the Stack is in Below')
            print(stack.stack_length())
            print("*********************\n*********************")
        elif choice == "4":
            print("Next Pop Item is in below")
            print(stack.peek())
            print("*********************\n*********************")
        elif choice == "5":
            print(stack.items)
            print("*********************\n*********************")


main()
