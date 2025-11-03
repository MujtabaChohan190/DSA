#include <iostream>
using namespace std;

// ---------------- Node Definition (BST Node) -------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// ---------------- Linked List Definition -------------------
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int value) {
        data = value;
        next = nullptr;
    }
};

// ---------------- BST Insertion ------------------- TO CREATE UNBALANCED TREE FIRST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// ---------------- Linked List Helper Functions -------------------

// Append node to Linked List
void appendToList(ListNode*& head, int value) {
    if (head == nullptr) {
        head = new ListNode(value);
        return;
    }

    ListNode* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = new ListNode(value);
}

// Get size of Linked List
int getListSize(ListNode* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

// Get value at a specific index in Linked List
int getValueAt(ListNode* head, int index) {
    int i = 0;
    while (head != nullptr) {
        if (i == index)
            return head->data;
        head = head->next;
        i++;
    }
    return -1; // should not happen if indices are correct
}

// Store inorder traversal of BST into Linked List - we store the values from unbalanced bst using inorder - inorder enusres we get sorted values and hence it stores it into linked list hence giving us sorted linked list for balanced bst
void storeInorder(Node* root, ListNode*& listHead) {
    if (root == nullptr)
        return;

    storeInorder(root->left, listHead);
    appendToList(listHead, root->data);
    storeInorder(root->right, listHead);
}

// ---------------- Convert Sorted Linked List → Balanced BST -------------------
Node* buildBalancedTree(ListNode* listHead, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2; // construct a balanced BST by picking the middle element of the linked list as the root for each subtree.
    int midVal = getValueAt(listHead, mid); //using getvalue at as arr[mid] , we get the value of mid index from getvalueat function

    Node* root = new Node(midVal);
    root->left = buildBalancedTree(listHead, start, mid - 1);
    root->right = buildBalancedTree(listHead, mid + 1, end);

    return root;
}

// HERE THE ALL THING WORKS , WE GET OUR LISTEAD AS NULL , WE IMPLEMENT INORDER , ABD THEN MAKE BALANCED TREE
Node* balanceBST(Node* root) {
    ListNode* listHead = nullptr;

    // 1. Store sorted inorder list
    storeInorder(root, listHead);

    // 2. Get size of list
    int n = getListSize(listHead);

    // 3. Build & return balanced BST
    return buildBalancedTree(listHead, 0, n - 1);
}

// ---------------- Inorder Print (to verify BST) -------------------
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------- Main -------------------
int main() {
    Node* root = nullptr;

    // Creating unbalanced BST
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 15);
    root = insert(root, 20);

    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;

    // Balancing BST
    root = balanceBST(root);

    cout << "Balanced BST (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
/*A linked list does NOT support indexing.

So if we want the mid element (to make it the root of the balanced BST), we must manually move through the list node-by-node until we reach that index.

That's exactly what getValueAt(listHead, mid) does:

start at listHead → move step-by-step → return mid-th value. ecause problem used Linked List, we needed a function to retrieve the value at index → hence getValueAt().*/
