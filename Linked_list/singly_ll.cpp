#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {      // Constructor
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // -------------------- INSERT AT HEAD --------------------
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // -------------------- INSERT AT END --------------------
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {        // If list empty
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {   // Move to last node
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // -------------------- INSERT AT POSITION --------------------
    // pos = 1 means insert at head
    void insertAtPosition(int value, int pos) {
        if (pos == 1) {
            insertAtHead(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // -------------------- DELETE BY VALUE --------------------
    void deleteByValue(int value) {
        if (head == NULL) return;

        // If the node to delete is the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found!\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // -------------------- DELETE AT POSITION --------------------
    void deleteAtPosition(int pos) {
        if (head == NULL) return;

        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position does not exist!\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // -------------------- SEARCH --------------------
    bool search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // -------------------- PRINT LIST --------------------
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// -------------------- MAIN FUNCTION --------------------
int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(5);
    list.insertAtTail(20);
    list.insertAtPosition(15, 3);

    cout << "List: ";
    list.printList();

    list.deleteByValue(10);
    cout << "After deleting 10: ";
    list.printList();

    list.deleteAtPosition(2);
    cout << "After deleting position 2: ";
    list.printList();

    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}
