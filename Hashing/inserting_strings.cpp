#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string word;  
    Node* next;    

    Node(string w) {
        word = w;
        next = nullptr;
    }
};

const int TABLE_SIZE = 13;
Node* table[TABLE_SIZE] = {nullptr}; 

// h(word) = (sum of ASCII values of all characters) % tableSize
int hashFunction(string word) {
    int sum = 0;

    // Add ASCII values of each character
    for (int i = 0; i < word.length(); i++) {
        sum += int(word[i]);
    }

    return sum % TABLE_SIZE;
}

// Insert a word into the hash table using chaining
void insertWord(string word) {

    // 1. Calculate the index using the hash function
    int index = hashFunction(word);

    // 2. Create a new node
    Node* newNode = new Node(word);

    // 3. If bucket is empty, place the node directly
    if (table[index] == nullptr) {
        table[index] = newNode;
    }
    else {
        // 4. Collision occurred → add new node at end of linked list
        Node* temp = table[index];

        // Traverse to the end of the list
        while (temp->next != nullptr) {

            // If word already exists, do not insert again
            if (temp->word == word) {
                delete newNode; // avoid duplicate insertion
                return;
            }
            temp = temp->next;
        }

        // Check last node before inserting
        if (temp->word == word) {
            delete newNode;
            return;
        }

        // Attach at end
        temp->next = newNode;
    }
}

// Display hash table and show collisions
void displayTable() {
    cout << "Hash Table (showing collisions):\n";
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";

        Node* temp = table[i];

        // If this index is empty
        if (temp == nullptr) {
            cout << "nullptr";
        }
        else {
            // Print the full chain at this index
            while (temp != nullptr) {
                cout << temp->word << " -> ";
                temp = temp->next;
            }
            cout << "nullptr";
        }

        cout << endl;
    }
}

int main() {

    // Given dictionary words
    string words[] = {"apple", "orange", "pear", "grape", "plum", "melon"};
    int n = 6;

    // Insert all words
    for (int i = 0; i < n; i++) {
        insertWord(words[i]);
    }

    // Display results
    displayTable();

    return 0;
}
