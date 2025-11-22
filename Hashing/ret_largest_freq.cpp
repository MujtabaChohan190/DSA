#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int key;    // element from array
    int value;  // frequency of the element
    Node* next;

    Node(int k, int val) {
        key = k;
        value = val;
        next = NULL;  // changed from nullptr to NULL
    }
};

// Hash table size
const int TABLE_SIZE = 10; // can be adjusted
Node* table[TABLE_SIZE] = {NULL};  // changed from nullptr to NULL

// Simple hash function
int hashFunction(int key) {
    if (key < 0) key = -key; // handle negative numbers
    return key % TABLE_SIZE;
}

// Insert or update frequency
void insert(int key) {
    int index = hashFunction(key);
    Node* temp = table[index];

    while (temp != NULL) { 
        if (temp->key == key) {
            temp->value += 1; // element exists, increment frequency
            return;
        }
        temp = temp->next;
    }

    // Element not found, insert new node with frequency 1
    Node* newNode = new Node(key, 1);
    newNode->next = table[index]; //table[index] is the current head of the linked list at this bucket. We want our new node to insert at the beginning of the linked list.
    table[index] = newNode; //we update the head of the linked list to be the new node.
}

// Function to find the most frequent element
int mostFrequent() {
    int maxFreq = 0;
    int result = -1;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table[i];
        while (temp != NULL) {  
            if (temp->value > maxFreq) {
                maxFreq = temp->value;
                result = temp->key;
            } else if (temp->value == maxFreq) {
                if (temp->key > result) result = temp->key; // pick largest element if tie
            }
            temp = temp->next;
        }
    }

    return result;
}

int main() {
    int arr[] = {1, 3, 2, 3, 4, 1, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insert all elements into hash table
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }

    int freqElem = mostFrequent();
    cout << "Most frequent element: " << freqElem << endl;

    return 0;
}
