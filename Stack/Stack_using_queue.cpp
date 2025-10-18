#include <queue>

class StackUsingQueue {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) cout << "Stack Underflow\n";
        else q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() { return q1.empty(); }
};
