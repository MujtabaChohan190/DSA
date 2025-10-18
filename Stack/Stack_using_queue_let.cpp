
#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size = 10) {
        cap = size;
        currSize = 0;
        arr = new int[cap];
        f = 0;
        r = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void push(int data) {
        if (currSize == cap) {
            cout << "Queue is FULL\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front() {
        if (empty()) {
            cout << "Queue is EMPTY\n";
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }

    bool full() {
        return currSize == cap;
    }
};

// Stack implemented using two circular queues
class MyStack {
    CircularQueue q1, q2;
    int capacity;

public:
    MyStack(int cap = 10) : q1(cap), q2(cap) {
        capacity = cap;
    }

    void push(int x) { // O(n)
        if (q1.full()) {
            cout << "Stack Overflow\n";
            return;
        }

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element 'x' to q1
        q1.push(x);

        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    MyStack s(size);

    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Empty\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            value = s.pop();
            if (value != -1)
                cout << "Popped: " << value << endl;
            break;
        case 3:
            cout << "Top: " << s.top() << endl;
            break;
        case 4:
            cout << (s.empty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
