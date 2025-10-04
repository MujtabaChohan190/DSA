class node {
public:
    node* next;
    node* prev;
    string val;

    node() : next(nullptr), prev(nullptr), val("") {}
    node(string data) : next(nullptr), prev(nullptr), val(data) {}
};

class BrowserHistory {
public:
    node* temp;

    BrowserHistory(string homepage) {
        temp = new node(homepage);
    }

    void visit(string url) {
        if (temp->next != nullptr)
            temp->next = nullptr;
        node* newnode = new node(url);
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode; //temp represents the current webpage on which system is at
    }

    string back(int steps) {
        node* t = temp;
        for (int i = 0; i < steps && t->prev; i++) {
            t = t->prev;
        }
        temp = t;
        return t->val;
    }

    string forward(int steps) {
        node* t = temp;
        for (int i = 0; i < steps && t->next; i++) {
            t = t->next;
        }
        temp = t;
        return t->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

