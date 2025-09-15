#include <iostream>
using namespace std;

class Node {
public:
    int sal;
    Node* next;

    Node(int s) {
        sal = s;
        next = NULL;
    }
};

class linkedList {
    Node* head;
    Node* tail;

public:
    linkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertNodeEnd(int s) {
        Node* newNode = new Node(s);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertNodeStart(int s) {
        Node* newNode = new Node(s);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printNode() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->sal << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* returnHead() {
        return head;
    }

    void selectionSort(Node* curr) {
        while (curr != NULL) {
            Node* min = curr;
            Node* forward = min->next;
            while (forward != NULL) {
                if (min->sal > forward->sal) {
                    min = forward;
                }
                forward = forward->next;
            }
            int temp = curr->sal;
            curr->sal = min->sal;
            min->sal = temp;
            curr = curr->next;
        }
    }
};

int main() {
    linkedList list;

    list.insertNodeEnd(30);
    list.insertNodeEnd(10);
    list.insertNodeEnd(50);
    list.insertNodeEnd(20);
    list.insertNodeEnd(40);

    cout << "Before Sorting: ";
    list.printNode();

    list.selectionSort(list.returnHead());

    cout << "After Sorting: ";
    list.printNode();

    return 0;
}

