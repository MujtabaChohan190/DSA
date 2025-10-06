#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class SinglyList {
    Node* head;
    Node* tail;
public:
    SinglyList() {
        head = NULL;
        tail = NULL;
    }

    void insertEnd(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void insertStart(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertMiddle(int d) {
        int pos;
        int count = 0;
        Node* newNode = new Node(d);
        cout << "Enter index position: ";
        cin >> pos;
        Node* temp = head;
        while (temp != NULL) {
            if (count == pos - 1) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
            count++;
        }
    }

    void deleteStart() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
    if (head == NULL)
    return;

    Node* temp = head;

   while (temp->next != tail) {
    temp = temp->next;
   }

   temp->next = NULL;
   delete tail;
    tail = temp;
}

    void deleteMiddle() {
        int pos;
        int count = 0;
        Node* temp = head;
        Node* prev = NULL;  // same as doubly, moved outside loop
        cout << "Enter index position: ";
        cin >> pos;

        while (temp != NULL) {
            if (count == pos) {
                prev->next = temp->next; // link previous node to next node
                delete temp;             // free current node
                return;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
    }

    void printNode() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl << endl;
    }

    void bubbleSort() {
        if (head == NULL || head->next == NULL)
            return; // No need to sort if 0 or 1 node

        bool swapped;

        do {
            swapped = false;
            Node* current = head;

            while (current->next != NULL) {
                if (current->data > current->next->data) {
                    // Swap the data of adjacent nodes
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next; // Move to next node
            }
        } while (swapped); // Repeat until no swaps occur (list is sorted)
    }

    // selection sort in the exact "array-style" for-loop format
    void selectionSort() {
        for (Node* i = head; i != NULL; i = i->next) {
            Node* min_node = i;
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (j->data < min_node->data) {
                    min_node = j;
                }
            }
            int temp = i->data;
            i->data = min_node->data;
            min_node->data = temp;
        }
    }
};

int main() {
    SinglyList s1;
    s1.insertEnd(11);
    s1.insertEnd(21);
    s1.insertEnd(3);
    s1.insertEnd(73);
    s1.insertEnd(10);
    s1.insertStart(91);
    s1.printNode();
    // s1.bubbleSort();
    s1.selectionSort();
    s1.printNode();
    return 0;
}
