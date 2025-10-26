#include <iostream>
using namespace std;

#define SIZE 100   // you can change size as needed

class MinStack {
    long long arr[SIZE];
    int top;
    long long minVal;

public:
    MinStack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        if (isEmpty()) {
            arr[++top] = val;
            minVal = val;
        } 
        else if (val < minVal) {
            arr[++top] = (long long)2 * val - minVal; // encoded value
            minVal = val;
        } 
        else {
            arr[++top] = val;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        if (arr[top] < minVal) {
            minVal = 2 * minVal - arr[top]; // decode old min
        }
        top--;
    }

    int topValue() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        if (arr[top] < minVal) {
            return minVal; // Encoded top element refers to min
        }
        return arr[top];
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return minVal;
    }
};

// ===============================
//            MAIN
// ===============================
int main() {
    MinStack s;
    int choice, value;

    while (true) {
        cout << "\n--- MIN STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Get Minimum\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout << "Top element: " << s.topValue() << endl;
                break;

            case 4:
                cout << "Current Min: " << s.getMin() << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
