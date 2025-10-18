#include <iostream>
using namespace std;

#define SIZE 5

// ===============================
//         STACK CLASS
// ===============================
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

    int size() { return top + 1; }

    // For internal use (to simulate stack transfer)
    int removeTop() {
        int val = peek();
        pop();
        return val;
    }
};

// ===============================
//         QUEUE USING STACKS
// ===============================
class QueueUsingStacks {
    StackArray s1, s2;

public:
    void enqueue(int x) { // O(n)
        if (s1.isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        // Move all elements from s1 to s2
        while (!s1.isEmpty()) {
            s2.push(s1.peek());
            s1.pop();
        }

        // Push new element to s1
        s1.push(x);

        // Move everything back to s1
        while (!s2.isEmpty()) {
            s1.push(s2.peek());
            s2.pop();
        }
    }

    void dequeue() { // O(1)
        if (s1.isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued: " << s1.peek() << endl;
        s1.pop();
    }

    int front() {
        if (s1.isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return s1.peek();
    }

    bool empty() {
        return s1.isEmpty();
    }

    void display() {
        if (s1.isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = s1.size() - 1; i >= 0; i--)
            cout << "[ " << i + 1 << " ] ";
        cout << endl;
    }
};

// ===============================
//             MAIN
// ===============================
int main() {
    QueueUsingStacks q;
    int choice, value;

    while (true) {
        cout << "\n--- QUEUE USING STACKS ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front Element\n";
        cout << "4. Empty Check\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << "Front element: " << q.front() << endl;
                break;

            case 4:
                cout << (q.empty() ? "Queue is Empty\n" : "Queue is Not Empty\n");
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

