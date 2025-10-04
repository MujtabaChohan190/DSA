#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    string val;

    Node(string data) : next(nullptr), prev(nullptr), val(data) {}
};

class BrowserHistory {
private:
    Node* current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        // Clear forward history
        if (current->next) {
            current->next = nullptr;
        }
        Node* newNode = new Node(url);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    string back(int steps) {
        while (steps-- > 0 && current->prev) {
            current = current->prev;
        }
        return current->val;
    }

    string forward(int steps) {
        while (steps-- > 0 && current->next) {
            current = current->next;
        }
        return current->val;
    }
};

/**
 * Usage:
 * BrowserHistory* obj = new BrowserHistory("homepage.com");
 * obj->visit("page1.com");
 * string backPage = obj->back(1);
 * string forwardPage = obj->forward(1);
 */
