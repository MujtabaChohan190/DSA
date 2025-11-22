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
    // 1. Calculate the initial index
    int index = hashFunction(key);
    int startIndex = index; // To detect if a full circle has been made (full table)

    // Linear probing for empty slot
    while (occupied[index]) {
        if (keys[index] == key) {
            // Update existing key
            values[index] = value;
            cout << "Updated key " << key << " with new value." << endl;
            return;
        }
        
        // Move to the next slot (probe)
        index = (index + 1) % SIZE;
        
        // Check if we've circled back to the starting index
        if (index == startIndex) {
            cout << "Hash table is full! Cannot insert." << endl;
            return;
        }
    }

    // Insert new key-value pair at the found empty slot (when occupied[index] is false)
    keys[index] = key;
    values[index] = value;
    occupied[index] = true;
    cout << "Inserted key " << key << " with value \"" << value << "\"." << endl;
}

// Delete a key
void remove(int key) {
    // 1. Calculate the initial index
    int index = hashFunction(key);
    int startIndex = index; // To detect if a full circle has been made

    // 2. Linear probe to find the key
    while (occupied[index]) {
        if (keys[index] == key) {
            // Key found: perform lazy deletion
            occupied[index] = false;
            cout << "Key " << key << " deleted." << endl;
            return;
        }
        
        // Move to the next slot (probe)
        index = (index + 1) % SIZE;
        
        // Check if we've circled back to the starting index without finding the key
        if (index == startIndex)
            break; // Stop probing
    }
    
    // 3. Key not found (loop exited because 'occupied[index]' was false or we broke out)
    cout << "Key " << key << " not found!" << endl;
}

// Search for a key
string search(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (occupied[index]) {
        if (keys[index] == key) {
            return values[index]; // Key found
        }

        index = (index + 1) % SIZE;
        if (index == startIndex)
            break; // Circled back to start
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
    remove(12); // Delete a key
    remove(7);
    remove(100); // Key not present

    cout << endl;
    display();

    return 0;
}
