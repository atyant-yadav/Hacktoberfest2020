#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int popped = q1.front();
        q1.pop();
        swap(q1, q2);
        return popped;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(topElement);
        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1, q2;
};

int main() {
    StackUsingQueues stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Top element: " << stack.top() << endl;
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

    return 0;
}
