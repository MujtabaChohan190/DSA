#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;        // assume current node is largest
    int left = 2 * i;       // left child index
    int right = 2 * i + 1;  // right child index

    // if left child exists and is greater
    if (left <= n && arr[left] > arr[largest])
        largest = left;

    // if right child exists and is greater
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    // if largest is not current node, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    int size = n;
    while (size > 1) {
        // Move current root (largest) to end
        swap(arr[1], arr[size]);
        size--;

        // Restore heap property on reduced heap
        heapify(arr, size, 1);
    }
}

int main() {
    // NOTE: We'll use 1-based indexing for simplicity
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // -1 is a dummy element
    int n = 5;

    cout << "Before Heap Sort: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "After Heap Sort: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

