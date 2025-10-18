class QueueArray {
    int arr[SIZE];
    int front, rear;
public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if (isFull()) cout << "Queue Overflow\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue Underflow\n";
        else front++;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
