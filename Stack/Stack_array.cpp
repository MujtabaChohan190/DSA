#include <iostream>
using namespace std;

#define SIZE 5

class StackArray {
    int arr[SIZE];
    int top;
public:
    StackArray() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }

    void push(int x) {
        if (isFull()) cout << "Stack Overflow\n";
        else arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) cout << "Stack Underflow\n";
        else top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};
