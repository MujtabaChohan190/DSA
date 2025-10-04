/*class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } 
        else { 
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
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

    // Function to insert node at the end
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

    // Function to print the list
    void printList(Node* node) {
        while (node != NULL) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};

// Solution class with merge function
class Solution {
public:
    Node* mergeTwoLists(Node* head1, Node* head2) {
        // Base case: if one list is empty
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // Recursive merging
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

int main() {
    LinkedList list1, list2;

    // First sorted list
    list1.insert(1);
    list1.insert(3);
    list1.insert(5);

    // Second sorted list
    list2.insert(2);
    list2.insert(4);
    list2.insert(6);

    Solution s;
    Node* mergedHead = s.mergeTwoLists(list1.head, list2.head);

    cout << "Merged Sorted List: ";
    list1.printList(mergedHead);

    return 0;
}

