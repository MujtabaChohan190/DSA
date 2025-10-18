class QueueList {
    Node* front;
    Node* rear;
public:
    QueueList() {
        front = rear = NULL;
    }

    bool isEmpty() { return front == NULL; }

    void enqueue(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue Underflow\n";
        else {
            Node* temp = front;
            front = front->next;
            if (front == NULL) rear = NULL;
            delete temp;
        }
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
