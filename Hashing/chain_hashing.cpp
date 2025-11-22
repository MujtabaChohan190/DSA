#include <iostream>
#include <string>
using namespace std;

// Node class for linked list
class Node {
public:
    int key;
    string value;
    Node* next;

    Node(int k, string val) {
        key = k;
        value = val;
        next = nullptr;
    }
};

// Hash table size
const int TABLE_SIZE = 5;
Node* table[TABLE_SIZE] = {nullptr}; // Initialize all to nullptr

// Simple hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert function
void insert(int key, string value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (table[index] == nullptr) {
        // No collision
        table[index] = newNode;
    } else {
        // Collision occurred -> add to the end of Linked List
        Node* temp = table[index]; //we start traversing from the head of the linked list 
        while (temp->next != nullptr) {
            if (temp->key == key) {
                // Update existing key
                temp->value = value; //we found the same key , so we update value for eg if its 7 cherry and our new node had 7 berry so now it becomes 7 berry
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        // Check Last node (if the key matches before adding a new node)
        if (temp->key == key) {
            temp->value = value;
            delete newNode;
            return;
        }

        temp->next = newNode;
    }
}

// Search function
string search(int key) {
    // 1. Calculate the index/bucket
    int index = hashFunction(key);
    
    // 2. Start traversal from the head of the linked list at that index
    Node* temp = table[index];

    // 3. Traverse the linked list until the end (nullptr) is reached
    while (temp != nullptr) {
        // 4. Check if the current node's key matches the search key
        if (temp->key == key) {
            return temp->value; // Key found, return the value
        }
        temp = temp->next; // Move to the next node
    }
    
    // 5. If the loop finishes without returning, the key wasn't found
    return "Key not found";
}

// Delete a key
void remove(int key) {
    // 1. Calculate the index/bucket
    int index = hashFunction(key);
    
    // 2. Start traversal pointers
    Node* temp = table[index]; // Current node being checked
    Node* prev = nullptr;      // Node immediately preceding 'temp'

    // 3. Traverse the list to find the key. Stop when:
    //    a) 'temp' reaches the end (nullptr), or
    //    b) 'temp->key' matches the target 'key'
    while (temp != nullptr && temp->key != key) {
        prev = temp;      // Move 'prev' to 'temp'
        temp = temp->next; // Move 'temp' to the next node
    }

    // 4. Key not found check
    if (temp == nullptr) {
        cout << "Key " << key << " not found!" << endl;
        return;
    }

    // 5. Key found - Perform deletion based on position
    if (prev == nullptr) {
        // Case A: Deleting the Head Node (temp is the head)
        // 'prev' is nullptr only if the key was found in the first node.
        table[index] = temp->next; // Remove Head node (update table entry)
    } else {
        // Case B: Deleting a Middle or Last Node
        // The node to be deleted is 'temp'. The preceding node is 'prev'.
        prev->next = temp->next; // Link 'prev' to the node *after* 'temp'
    }

    // 6. Free the memory of the deleted node
    delete temp;
    cout << "Key " << key << " deleted successfully." << endl;
}

// Function to display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* temp = table[i];
        while (temp != nullptr) {
            cout << "(" << temp->key << ", " << temp->value << ") -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
}

// Main function
int main() {
    insert(12, "Apple");
    insert(7, "Banana");
    insert(17, "Cherry");
    insert(22, "Date");
    insert(7, "Blueberry"); // Update existing key

    cout << "Initial hash table:" << endl;
    display();
    cout << endl;

    cout << "Search for key 17: " << search(17) << endl;
    cout << "Search for key 5: " << search(5) << endl; // Key not present
    cout << endl;

    remove(12); // Delete head node in index 2
    remove(7);  // Delete middle node in index 2
    remove(100); // Key not present

    cout << "\nHash table after deletions:" << endl;
    display();

    return 0;
}
