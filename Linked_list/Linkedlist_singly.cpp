#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        
        if (head == NULL) {
            tail = NULL;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) { 
            temp = temp->next;
        }

        Node* oldTail = tail;
        temp->next = NULL;
        delete oldTail;

        tail = temp;
    }

    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "invalid pos\n";
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "invalid pos\n";
                return;
            }
            temp = temp->next;
        }
        
        if (temp == NULL) {
             cout << "invalid pos\n";
             return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }
    
    void deleteAfter(int pos) {
        if (head == NULL) return;
        if (pos <= 0) {
            pop_front();
            return;
        }

        Node* pre = NULL;
        Node* curr = head;
        
        for(int i = 0; i < pos; i++) { 
            if (curr == NULL) return;
            pre = curr;
            curr = curr->next;
        }
        
        if (curr == NULL) return;
        
        pre->next = curr->next;
        
        if (curr == tail) {
            tail = pre;
        }
        
        delete curr;
    }

    int search(int key) {
        Node* temp = head;
        int idx = 0;

        while (temp != NULL) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    
    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* middleNode() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = head;
        head = prev;
    }
};

int main() {
    List myList;
    
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);
    
    cout << "Original List: ";
    myList.printLL();

    Node* middle = myList.middleNode();
    if (middle) {
        cout << "Middle Node Data: " << middle->data << endl;
    }
    
    myList.reverse();
    cout << "Reversed List: ";
    myList.printLL();

    middle = myList.middleNode();
    if (middle) {
        cout << "Middle Node Data (Reversed): " << middle->data << endl;
    }

    return 0;
}
