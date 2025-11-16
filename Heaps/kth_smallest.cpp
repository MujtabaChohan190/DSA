#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    int priority;
    Node* next;
    Node(int val, int pri) : value(val), priority(pri), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void insert(int val) {
        Node* newNode = new Node(val, val);

        if (front == NULL || val > front->priority) {
            newNode->next = front;
            front = newNode;
        } 
        else {
            Node* current = front;
            while (current->next != NULL && current->next->priority >= val) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove() {
        if (front == NULL) return;
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if (front == NULL) return -1;
        return front->value;
    }
};

int kthSmallest(int arr[], int l, int r, int k) {
    PriorityQueue p;

    for (int i = 0; i < k; i++)
        p.insert(arr[i]);

    for (int i = k; i <= r; i++) {
        if (arr[i] < p.peek()) {
            p.remove();
            p.insert(arr[i]);
        }
    }

    return p.peek();
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    cout << kthSmallest(arr, 0, n - 1, k);

    return 0;
}
