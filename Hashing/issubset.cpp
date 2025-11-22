#include <iostream>
using namespace std;

// Node class for linked list (used for chaining)
class Node {
public:
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = nullptr;
    }
};

const int TABLE_SIZE = 13;
Node* hashTable[TABLE_SIZE] = {nullptr}; // Initialize all to nullptr

// Simple hash function
int hashFunction(int x) {
    return x % TABLE_SIZE;
}

// Insert element into hash table using chaining
void insert(int x) {
    int index = hashFunction(x);
    Node* newNode = new Node(x);

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Search for an element in the hash table
bool search(int x) {
    int index = hashFunction(x);
    Node* temp = hashTable[index];

    while (temp != nullptr) {
        if (temp->key == x)
            return true;
        temp = temp->next;
    }
    return false;
}

// Function to check if b[] is a subset of a[]
bool isSubset(int a[], int m, int b[], int n) {
    // Step 1: Insert all elements of a[] into hash table
    for (int i = 0; i < m; i++)
        insert(a[i]);

    // Step 2: Check each element of b[] in hash table
    for (int j = 0; j < n; j++) {
        bool found = search(b[j]);  // search() returns true if element exists
        if (found == false) {       // explicitly check for false
            return false;           // Element of b[] not found
        }
    }
    return true; // All elements of b[] found
}

int main() {
    int a[] = {11, 1, 13, 21, 3, 7};
    int b[] = {11, 3, 7, 1};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    if (isSubset(a, m, b, n))
        cout << "b[] IS a subset of a[]" << endl;
    else
        cout << "b[] is NOT a subset of a[]" << endl;

    return 0;
}

