#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class StackList {
    Node* top;
public:
    StackList() { top = NULL; }

    bool isEmpty() { return top == NULL; }

    void push(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (isEmpty()) cout << "Stack Underflow\n";
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ===============================
//            MAIN
// ===============================
int main() {
    StackList s;
    int choice, value;

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top Element)\n";
        cout << "4. Display\n";
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
                cout << "Top element is: " << s.peek() << endl;
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
