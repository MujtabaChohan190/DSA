#include <iostream>
using namespace std;

#define TABLE_SIZE 100

int hashFunc(int key) {
    return key % TABLE_SIZE;
}

void insertKey(int table[], int key) {
    int index = hashFunc(key);
    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index] = key;
}

bool searchKey(int table[], int key) {
    int index = hashFunc(key);
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key)
            return true;
        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            return false;
    }
    return false;
}

bool isSubset(int a[], int m, int b[], int n) {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = -1;

    for (int i = 0; i < m; i++)
        insertKey(table, a[i]);

    for (int i = 0; i < n; i++) {
        if (!searchKey(table, b[i]))
            return false;
    }
    return true;
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {20, 40};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    if (isSubset(a, m, b, n))
        cout << "b[] IS a subset of a[]";
    else
        cout << "b[] is NOT a subset of a[]";

    return 0;
}
