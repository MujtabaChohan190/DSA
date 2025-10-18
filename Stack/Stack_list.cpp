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
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
