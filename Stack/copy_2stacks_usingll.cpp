#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char d) {
        data = d;
        next = NULL;
    }
};

class StackList {
    Node* top;
public:
    StackList() { top = NULL; }

    bool isEmpty() { return top == NULL; }

    void push(char x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        Node* temp = top;
        char popped = temp->data;
        top = top->next;
        delete temp;
        return popped;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return '\0';
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

// 🔹 Function to copy S1 → S2 (no friend needed)
void copyStack(StackList *S1, StackList *S2) {
    StackList temp;

    // Step 1: Pop all from S1 → push into temp
    while (!S1->isEmpty()) {
        char ch = S1->pop();
        temp.push(ch);
    }

    // Step 2: Pop from temp → push into S1 and S2 (restores order)
    while (!temp.isEmpty()) {
        char ch = temp.pop();
        S1->push(ch);   // restore S1
        S2->push(ch);   // copy to S2
    }
}

int main() {
    StackList S1, S2;

    S1.push('A');
    S1.push('B');
    S1.push('C');

    cout << "Original Stack (S1): ";
    S1.display();

    copyStack(&S1, &S2);

    cout << "Copied Stack (S2): ";
    S2.display();

    cout << "After Copy, Original Stack (S1): ";
    S1.display();

    return 0;
}


/*If we traverse S1 from top to bottom and directly push data into S2,
the order will get reversed.*/
