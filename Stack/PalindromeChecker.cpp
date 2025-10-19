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

bool isPalindrome(string str) {
    StackList s;
    int len = str.length();
    
    // Push all characters onto stack
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }
     // Pop each character and compare

    for (int i = 0; i < len; i++) {
        char ch = s.pop();
        if (ch != str[i])
            return false;
    }

    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}
