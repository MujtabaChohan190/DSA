/*class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};*/

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = NULL;
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Function to insert new node at end
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

    // Function to create a cycle manually (for testing)
    void createCycle(int pos) {
        if (pos == -1) return; // No cycle
        Node* temp = head;
        Node* cycleNode = NULL;
        int count = 1;
        while (temp->next != NULL) {
            if (count == pos) cycleNode = temp;
            temp = temp->next;
            count++;
        }
        temp->next = cycleNode; // Connect end to position node
    }

    // Detect if the linked list has a cycle
    bool hasCycle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // Cycle found
            }
        }
        return false; // No cycle
    }
};

int main() {
    LinkedList list;

    // Insert elements
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    // Create cycle (connect last node to node 2)
    list.createCycle(2);

    if (list.hasCycle()) {
        cout << "Cycle detected in linked list." << endl;
    } else {
        cout << "No cycle in linked list." << endl;
    }

    return 0;
}
