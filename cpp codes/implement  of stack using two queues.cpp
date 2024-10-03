// Implementing stack using two queues

#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2; // Two queues
    int currentSize; // Current size of the stack

public:
    Stack() {
        currentSize = 0; // Initialize size
    }

    // Push operation
    void push(int x) {
        // Push x to q2
        q2.push(x);
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap names of q1 and q2
        swap(q1, q2);
        currentSize++; // Increment size
    }

    // Pop operation
    void pop() {
        if (!q1.empty()) {
            q1.pop(); // Remove element from top
            currentSize--; // Decrement size
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    // Top operation
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // Indicate that stack is empty
    }

    // Size operation
    int size() {
        return currentSize;
    }

    // IsEmpty operation
    bool isEmpty() {
        return currentSize == 0;
    }

    // Print stack operation
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";

        // Create a temporary queue to print elements without modifying the original queue
        queue<int> temp = q1;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Is Empty\n";
        cout << "6. Print Stack\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Push operation
                while (true) {
                    cout << "Enter value to push (or 0 to stop): ";
                    cin >> value;
                    if (value == 0) { // Stop pushing if user enters 0
                        break;
                    }
                    s.push(value);
                    cout << value << " pushed onto stack." << endl;
                }
                break;
            }
            case 2: // Pop operation
                s.pop();
                cout << "Top element popped." << endl;
                break;
            case 3: // Top operation
                value = s.top();
                if (value != -1) {
                    cout << "Top element is: " << value << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4: // Size operation
                cout << "Current size of the stack: " << s.size() << endl;
                break;
            case 5: // Is Empty operation
                cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 6: // Print Stack operation
                s.printStack();
                break;
            case 0: // Exit operation
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 0); // Continue until user chooses to exit

    return 0;
}
