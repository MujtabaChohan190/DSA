#define SIZE 100
class NodeQueue {
    Node* arr[SIZE];
    int front, rear;
public:
    NodeQueue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(Node* x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() { if (!isEmpty()) front++; }
    Node* Front() { return isEmpty() ? NULL : arr[front]; }
};

void levelOrderByLevel(Node* root) {
    if (root == NULL) {
        return;
    }

    NodeQueue q;
    q.enqueue(root);
    q.enqueue(NULL); // Level delimiter

    while (!q.isEmpty()) {
        Node* curr = q.Front();
        q.dequeue();

        if (curr == NULL) {
            cout << endl; // End of one level
            if (!q.isEmpty()) {
                q.enqueue(NULL); // Add new delimiter for next level
            }
        } 
        else {
            cout << curr->data << " ";

            if (curr->left != NULL) {
                q.enqueue(curr->left);
            }
            if (curr->right != NULL) {
                q.enqueue(curr->right);
            }
        }
    }
}
