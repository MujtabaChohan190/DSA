#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    // Insert node at the end
    void insertEnd(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Insert node at the start
    void insertStart(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert node in the middle at given position
    void insertMiddle(int d) {
        int pos;
        int count = 0;
        Node* newNode = new Node(d);
        cout << "Enter index position: ";
        cin >> pos;

        Node* temp = head;
        while (temp != NULL) {
            if (count == pos - 1) {
                newNode->prev = temp;
                newNode->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
            count++;
        }
    }

    // Delete node from start
    void deleteStart() {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    // Delete node from end
    void deleteEnd() {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    // Delete node from a specific position
    void deleteMiddle() {
        int pos;
        int count = 0;
        Node* temp = head;
        Node* prev = NULL;  // Fixed: moved outside loop
        cout << "Enter index position: ";
        cin >> pos;

        while (temp != NULL) {
            if (count == pos) {
                prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = prev;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
    }

    // Display all nodes
    void printNode() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl << endl;
    }

    // Insertion Sort for Doubly Linked List
    void insertionSort() {
        // If list is empty or has only one node, no need to sort
        if (head == NULL || head->next == NULL)
            return;

        // Start from the second node (first node is already "sorted" initially)
        Node* current = head->next;

        // Traverse the list from 2nd node till the end
        while (current != NULL) {

            int key = current->data;          // Store the value of current node (this is what we'll insert in sorted part)
            Node* previous = current->prev;   // Pointer to the previous node for backward comparison

            // Move backwards through the sorted part and shift data forward
            while (previous != NULL && previous->data > key) {
                previous->next->data = previous->data;  // Shift data of previous node one step ahead
                previous = previous->prev;              // Move backward
            }

            // After finding correct position, insert the stored 'key' value
            if (previous == NULL)
                head->data = key;               // If reached start, place key at head
            else
                previous->next->data = key;     // Else, place key after the correct position

            // Move to the next node in the original list
            current = current->next;
        }
    }
};

int main() {
    DoublyList s1;

    // Insert nodes
    s1.insertEnd(11);
    s1.insertEnd(21);
    s1.insertEnd(3);
    s1.insertEnd(73);
    s1.insertEnd(10);
    s1.insertStart(91);

    cout << "Before sorting:\n";
    s1.printNode();

    s1.insertionSort();

    cout << "After sorting:\n";
    s1.printNode();

    // Uncomment to test deletions:
    // s1.deleteMiddle();
    // s1.printNode();
    // s1.deleteEnd();
    // s1.printNode();
    // s1.deleteStart();
    // s1.printNode();

    return 0;
}
