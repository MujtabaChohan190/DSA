#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long value;     
    Node* next;        

    Node(long long val) : value(val), next(nullptr) {}
};
//min priority queue 
class PriorityQueue {
private:
    Node* front; 
    int count; // Added count variable

public:
    PriorityQueue() : front(nullptr), count(0) {} // Initialize count to 0

    ~PriorityQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // New accessor method for size
    int size() const {
        return count;
    }

    bool isEmpty() const {
        return front == NULL;
    }

    void insert(long long val) {
        Node* newNode = new Node(val);
        count++; // Increment count on insert

        if (front == NULL || val < front->value) {
            newNode->next = front;
            front = newNode;
        } 
        else {
            Node* current = front;
            while (current->next != NULL && current->next->value <= val) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove() {
        if (front == NULL) {
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        count--; // Decrement count on remove
    }

    long long peek() {
        if (front == NULL) {
            return -1; 
        }
        return front->value;
    }
};

// ## Min Cost of Ropes Solution ##
long long minCost(long long arr[], int n) {
    PriorityQueue pq;

    for (int i = 0; i < n; i++) {
        pq.insert(arr[i]);
    }

    long long totalCost = 0;

    // Loop runs exactly until only one rope remains (i.e., size == 1)
    while (pq.size() > 1) { 
        long long a = pq.peek();
        pq.remove();

        long long b = pq.peek();
        pq.remove();

        long long sum = a + b;

        totalCost += sum;

        pq.insert(sum);
    }

    return totalCost;
}

int main() {
    long long arr[] = {4, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long result = minCost(arr, n);

    cout << "Minimum Cost to connect all ropes: " << result << endl; // Output: 29

    return 0;
}
