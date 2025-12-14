#include <iostream>
#include <string>
using namespace std;

// Hash table size
const int SIZE = 5;

// Arrays to store keys and values
int keys[SIZE];
string values[SIZE];
bool occupied[SIZE] = {false}; // Track which slots are occupied

// Primary hash function
int hash1(int key) {
    return key % SIZE;
}

// Secondary hash function (must be non-zero, relatively prime to SIZE)
int hash2(int key) {
    return 1 + (key % (SIZE - 1)); // ensures step size ≠ 0
}

// Insert key-value pair
void insert(int key, string value) {
    int index = hash1(key);
    int startIndex = index;
    int i = 0; // iteration count

    while (occupied[index]) {
        if (keys[index] == key) {
            // Update existing key
            values[index] = value;
            cout << "Updated key " << key << " with new value." << endl;
            return;
        }

        i++;
        index = (hash1(key) + i * hash2(key)) % SIZE; // double hashing

        if (i >= SIZE) {
            cout << "Hash table is full! Cannot insert." << endl;
            return;
        }
    }

    keys[index] = key;
    values[index] = value;
    occupied[index] = true;
    cout << "Inserted key " << key << " with value \"" << value << "\"." << endl;
}

// Delete a key
void remove(int key) {
    int index = hash1(key);
    int startIndex = index;
    int i = 0;

    while (occupied[index]) {
        if (keys[index] == key) {
            occupied[index] = false; // lazy deletion
            cout << "Key " << key << " deleted." << endl;
            return;
        }

        i++;
        index = (hash1(key) + i * hash2(key)) % SIZE;

        if (i >= SIZE) break; // fully probed table
    }

    cout << "Key " << key << " not found!" << endl;
}

// Search for a key
string search(int key) {
    int index = hash1(key);
    int i = 0;

    while (occupied[index]) {
        if (keys[index] == key) {
            return values[index];
        }

        i++;
        index = (hash1(key) + i * hash2(key)) % SIZE;

        if (i >= SIZE) break; // fully probed
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
