#include <iostream>
using namespace std;

// Node structure for Priority Queue
struct Node {
    int value;     // The value of the element
    int priority;  // The priority of the element
    Node* next;    // Pointer to the next node in the queue

    Node(int val, int pri) : value(val), priority(pri), next(nullptr) {}
};

// Priority Queue class (implemented using linked list)
class PriorityQueue {
private:
    Node* front; // Pointer to the front (highest priority) node

public:
    // Constructor
    PriorityQueue() : front(nullptr) {}

    // Destructor to free all allocated memory
    ~PriorityQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Insert a new element with a given priority
    void insert(int val, int pri) {
        Node* newNode = new Node(val, pri);

        // If queue is empty OR new node has higher priority than front
        if (front == NULL || pri > front->priority) {
            newNode->next = front;
            front = newNode;
        } 
        else {
            // Find correct position based on priority
            Node* current = front;
            while (current->next != NULL && current->next->priority >= pri) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Remove the element with the highest priority (at front)
    void remove() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Get (peek) the element with the highest priority
    int peek() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return -1; // Return an error value
        }
        return front->value;
    }

    // Print the entire queue (front → back)
    void printQueue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* current = front;
        while (current != NULL) {
            cout << "(" << current->value << ", " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to test the Priority Queue
int main() {
    PriorityQueue pq;

    pq.insert(10, 2);
    pq.insert(20, 4);
    pq.insert(30, 3);
    pq.insert(40, 5);

    cout << "Priority Queue: ";
    pq.printQueue();

    cout << "Top element (highest priority): " << pq.peek() << endl;

    pq.remove();
    cout << "After removing top element: ";
    pq.printQueue();

    return 0;
}
