#define SIZE 100

class NodeQueue {
    Node* arr[SIZE];
    int front, rear;

public:
    NodeQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(Node* x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    Node* Front() {
        if (isEmpty()) return NULL;
        return arr[front];
    }
};
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    NodeQueue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        Node* curr = q.Front();
        q.dequeue();

        cout << curr->data << " ";

        if (curr->left != NULL) {
            q.enqueue(curr->left);
        }
        if (curr->right != NULL) {
            q.enqueue(curr->right);
        }
    }
    cout << endl;
}
