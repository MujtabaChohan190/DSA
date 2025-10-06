#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    long data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end
    void insert(long value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Selection Sort for linked list
    void selectionSort() {
        for (Node* i = head; i != NULL; i = i->next) {
            Node* min_node = i;
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (j->data < min_node->data) {
                    min_node = j;
                }
            }
            long temp = i->data;
            i->data = min_node->data;
            min_node->data = temp;
        }
    }

    // Simple linear search in linked list
    bool search(long value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

// Main function
int main() {
    LinkedList list;
    int n;
    long value, searchValue;

    cout << "Enter number of registration numbers: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    cout << "\nOriginal list:\n";
    list.display();

    list.selectionSort();

    cout << "\nSorted list using Selection Sort:\n";
    list.display();

    cout << "\nEnter registration number to search: ";
    cin >> searchValue;

    if (list.search(searchValue))
        cout << "Registration number " << searchValue << " found in the list.\n";
    else
        cout << "Registration number " << searchValue << " not found in the list.\n";

    return 0;
}
