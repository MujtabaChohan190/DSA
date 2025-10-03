#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert new node at the end
    void insert(int data) {
        Node* newNode = new Node(data);
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

    // Print the linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Reverse the linked list (iterative)
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;   // save next node
            curr->next = prev;   // reverse pointer
            prev = curr;         // move prev
            curr = next;         // move curr
        }
        head = prev; // update head
    }
};

// Main function
int main() {
    LinkedList list;

    // Insert some elements
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original List: ";
    list.printList();

    // Reverse the list
    list.reverse();

    cout << "Reversed List: ";
    list.printList();

    return 0;
}


//
//LEETCODE
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
};  we return head bcs we need to tell the caller of leetcode form where to locate head to read the list */
