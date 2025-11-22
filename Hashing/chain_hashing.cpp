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

// Hash: sum of ASCII characters % table size
int hashFunction(string word) {
    int sum = 0;
    for (int i = 0; i < word.length(); i++) {
        sum += int(word[i]);
    }
    return sum % TABLE_SIZE;
}

// Insert using chaining
void insertWord(string word) {
    int index = hashFunction(word);
    Node* newNode = new Node(word);

    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* temp = table[index];
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display all collisions
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* temp = table[i];
        if (temp == nullptr) {
            cout << "null";
        } else {
            while (temp != nullptr) {
                cout << temp->word << " -> ";
                temp = temp->next;
            }
            cout << "null";
        }
        cout << endl;
    }
}

int main() {
    insertWord("apple");
    insertWord("orange");
    insertWord("pear");
    insertWord("grape");
    insertWord("plum");
    insertWord("melon");

    display();
    return 0;
}


