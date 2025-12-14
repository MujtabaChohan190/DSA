#include <iostream>
#include <string>
using namespace std;

// Hash table size
const int SIZE = 5;

// Arrays to store keys and values
int keys[SIZE];
string values[SIZE];
bool occupied[SIZE] = {false}; // Track which slots are occupied

// Simple hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert key-value pair
void insert(int key, string value) {
    int index = hashFunction(key);
    int startIndex = index; // To detect if a full circle has been made

    // Linear probing for empty slot
    while (occupied[index]) {
        if (keys[index] == key) {
            // Update existing key
            values[index] = value;
            cout << "Updated key " << key << " with new value." << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            cout << "Hash table is full! Cannot insert." << endl;
            return;
        }
    }

    // Insert new key-value pair
    keys[index] = key;
    values[index] = value;
    occupied[index] = true;
    cout << "Inserted key " << key << " with value \"" << value << "\"." << endl;
}

// Delete a key
void remove(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (occupied[index]) {
        if (keys[index] == key) {
            occupied[index] = false; // Lazy deletion
            cout << "Key " << key << " deleted." << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == startIndex) break; // Circled back to start
    }

    cout << "Key " << key << " not found!" << endl;
}

// Search for a key
string search(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (occupied[index]) {
        if (keys[index] == key) {
            return values[index];
        }
        index = (index + 1) % SIZE;
        if (index == startIndex) break; // Circled back to start
    }

    return "Key not found";
}

// Display the hash table
void display() {
    cout << "Hash Table:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        if (occupied[i])
            cout << "(" << keys[i] << ", " << values[i] << ")";
        else
            cout << "Empty";
        cout << endl;
    }
}

// Main function
int main() {
    insert(12, "Apple");
    insert(7, "Banana");
    insert(17, "Cherry");
    insert(22, "Date");
    insert(7, "Blueberry"); // Update existing key

    cout << endl;
    display();
    cout << endl;

    cout << "Search for key 17: " << search(17) << endl;
    cout << "Search for key 5: " << search(5) << endl;

    cout << endl;
    remove(12);
    remove(7);
    remove(100); // Key not present

    cout << endl;
    display();

    return 0;
}
