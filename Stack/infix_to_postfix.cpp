#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int val) {
        if (top < capacity - 1) {
            arr[++top] = val;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    int peek() {
        if (top != -1) {
            return arr[top];
        }
        return -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int performOperation(int operand1, int operand2, char op) {
    if (op == '+') {
        return operand1 + operand2;
    } else if (op == '-') {
        return operand1 - operand2;
    } else if (op == '*') {
        return operand1 * operand2;
    } else if (op == '/') {
        return operand1 / operand2;
    }
    return 0;
}

int evaluatePostfix(const string& postfix) {
    Stack s(postfix.length());

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = s.pop();
            int operand1 = s.pop();
            int result = performOperation(operand1, operand2, c);
            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
