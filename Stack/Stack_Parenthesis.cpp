#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

class Stack {
    int topIndex;
public:
    char a[MAX]; 
    Stack() { topIndex = -1; }

    bool push(char x);
    void pop();
    char top();
    int size();
};

bool Stack::push(char x) {
    if (topIndex >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    } else {
        a[++topIndex] = x;
        return true;
    }
}

void Stack::pop() {
    if (topIndex < 0) {
        cout << "Stack Underflow\n";
    } else {
        topIndex--;
    }
}

char Stack::top() {
    if (topIndex < 0) {
        cout << "Stack is Empty\n";
        return '\0';
    } else {
        return a[topIndex];
    }
}

int Stack::size() {
    return topIndex + 1;
}

bool isValid(const string& str) {
    Stack st;

    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else {
            if (st.size() == 0) {
                return false;
            }
            char topChar = st.top();
            if ((topChar == '(' && str[i] == ')') || 
                (topChar == '{' && str[i] == '}') || 
                (topChar == '[' && str[i] == ']')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.size() == 0;
}

int main() {
    string test1 = "(){}[]";
    string test2 = "({[)]}";
    string test3 = "({[]})";

    cout << boolalpha;
    cout << "Test 1: " << isValid(test1) << "\n";  // true
    cout << "Test 2: " << isValid(test2) << "\n";  // false
    cout << "Test 3: " << isValid(test3) << "\n";  // true

    return 0;
}
