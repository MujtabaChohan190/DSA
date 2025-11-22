#include <iostream>
using namespace std;

class HashTable {
private:
    int *table;
    bool *deleted;
    int capacity;
    int size;

    int hashFunc(int key) {
        return key % capacity;
    }

    void rehash() {
    	
    	//1- Save the old table , old capacity and old deleted array
    	//2- Double the capacity and find the next prime.
    	
        int oldCapacity = capacity;
        capacity = nextPrime(2 * capacity);

        int *oldTable = table;       
        bool *oldDeleted = deleted;
        
        //3-Allocate new arrays for the table and deleted slots.      
        table = new int[capacity];
        deleted = new bool[capacity];
        
        //4- Initialize array
        for (int i = 0; i < capacity; i++) {
            table[i] = -1;
            deleted[i] = false;
        }
        //Reset the size counter because we will re-insert all elements into the new table.
        size = 0;

        //slot had a key and the key wasn’t deleted , then insert from old table
        for (int i = 0; i < oldCapacity; i++) {
            if (oldTable[i] != -1 && !oldDeleted[i]) {
                insert(oldTable[i]);
            }
        }

        delete[] oldTable;
        delete[] oldDeleted;

        cout << "Rehash completed. New capacity = " << capacity << endl;
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

public:
    HashTable(int cap = 10) {
        capacity = cap;
        size = 0;

        table = new int[capacity];
        deleted = new bool[capacity];

        for (int i = 0; i < capacity; i++) {
            table[i] = -1;
            deleted[i] = false;
        }
    }

    double loadFactor() {
        return (double) size / capacity;
    }
    //function to insert a new key into the hash table.
    void insert(int key) {
        if (loadFactor() > 0.7) {
            rehash();
        }

        int index = hashFunc(key);
        //Handle collisions using linear probing. Loop continues while: the slot is already occupied by a key. the slot is not marked as deleted
        while (table[index] != -1 && !deleted[index]) {
            index = (index + 1) % capacity;
        }
        //Place the key in the found slot
        table[index] = key;
        deleted[index] = false; //mark this slot as not deleted.
        size++; //increment the count of active elements in the table.

        cout << key << " inserted.\n";
    }

    bool search(int key) {
        int index = hashFunc(key);
        int start = index;

        while (table[index] != -1 || deleted[index]) {
        	//traverse the table while theres a chance that key is in the table even though slot was deleted , we might have probed keys further
        	//checking if current slot has our key and its not marked as deleted
            if (table[index] == key && !deleted[index]) {
                cout << key << " found at index " << index << endl;
                return true;
            }
            //if key is not at that slot , linear probe 
            index = (index + 1) % capacity;
            //top searching if we’ve come full circle back to the starting index
            if (index == start) break;
        }

        cout << key << " not found.\n";
        return false;
    }

    void remove(int key) {
        int index = hashFunc(key);
        int start = index;

        while (table[index] != -1 || deleted[index]) {
            if (table[index] == key && !deleted[index]) {
                deleted[index] = true;
                table[index] = -1;
                size--;
                cout << key << " deleted.\n";
                return;
            }
            //if key wasnt available on that slot so linear probe
            index = (index + 1) % capacity;
            if (index == start) break;
        }

        cout << key << " not found. Cannot delete.\n";
    }

    void print() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < capacity; i++) {
            if (table[i] == -1 && !deleted[i])
                cout << i << ": EMPTY\n";
            else if (deleted[i])
                cout << i << ": DELETED\n";
            else
                cout << i << ": " << table[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    HashTable ht(10);

    int keys[] = {10, 25, 35, 45, 55, 65, 75};
    int n = 7;

    for (int i = 0; i < n; i++) {
        ht.insert(keys[i]);
    }
    ht.print();

    return 0;
}
