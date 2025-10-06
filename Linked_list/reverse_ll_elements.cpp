#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class singlyll {
public:
    node* head;
    node* tail;

    singlyll() {
        head = NULL;
        tail = NULL;
    }

    void insertend(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = tail = n;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    // Recursive function to print list in reverse order
    void printreverse(node* head) {
        if (head == NULL) {
            return;
        }
        printreverse(head->next);
        cout << head->data << " ";
    }
};


int main() {
    singlyll list;

    list.insertend(10);
    list.insertend(20);
    list.insertend(30);
    list.insertend(40);

    cout << "Linked list printed in reverse order: ";
    list.printreverse(list.head);   // Works directly since head is public

    return 0;
}
