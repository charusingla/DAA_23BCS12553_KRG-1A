#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Stack {
private:
    int stackArray[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize top to -1 for an empty stack
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            stackArray[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1; // Or throw an exception
        } else {
            int poppedValue = stackArray[top--];
            cout << poppedValue << " popped from stack." << endl;
            return poppedValue;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
            return -1; 
        } else {
            return stackArray[top];
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop(); // Attempt to pop from an empty stack

    return 0;
}