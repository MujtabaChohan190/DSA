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

    void print
