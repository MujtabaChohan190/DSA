#include <iostream>
using namespace std;

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

void linearSearchOccurrences(int arr[], int n, int key) {
    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (first == -1) {
                first = i;   // it helps to store the first occurrence only once
            } else {        // here if already found once, we just update last
                last = i;
            }
        } else {            // if it isn’t available in array do nothing here
        }
    }

    if (first != -1) {
        if (last == -1) {   // if last never got updated, it means only one occurrence , SO  last = first
            last = first;
        }
        cout << "Salary " << key << " found." << endl;
        cout << "First occurrence at index: " << first << endl;
        cout << "Last occurrence at index: " << last << endl;
    } else {
        cout << "Salary " << key << " not found." << endl;
    }
}

int main() {
    int salaries[7] = {50000, 70000, 60000, 50000, 90000, 70000, 80000};
    int n = 7;

    selectionSortDescending(salaries, n);

    int key = 70000;
    linearSearchOccurrences(salaries, n, key);

    return 0;
}
