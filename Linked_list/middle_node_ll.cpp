#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int v) {
        Node* newNode = new Node(v);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node* middleNode() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 steps
        }
        return slow; // slow will be at middle
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);

    Node* mid = list.middleNode();
    cout << "Middle node value is: " << mid->val << endl;
    return 0;
}
