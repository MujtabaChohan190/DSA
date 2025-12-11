#include <iostream>
using namespace std;

class MaxHeap {
public:
    int* arr;
    int capacity;
    int size;

    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity + 1]; // 1-based indexing
        arr[0] = -1;                 // dummy
    }

    ~MaxHeap() {
        delete[] arr;
    }

    // -------- MAX HEAP INSERTION --------
    void insert(int val) {
        if(size == capacity) return; // heap full
        size++;
        int idx = size;
        arr[idx] = val;

        // Heapify Up
        while(idx > 1) {
            int parent = idx / 2;
            if(arr[parent] < arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            } else {
                return;
            }
        }
    }

    // -------- MAX HEAPIFY (downward) --------
    void maxHeapify(int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= size && arr[left] > arr[largest])
            largest = left;
        if(right <= size && arr[right] > arr[largest])
            largest = right;

        if(largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    // -------- REMOVE MAX (root) --------
    void removeMax() {
        if(size == 0) return;
        arr[1] = arr[size];
        size--;
        maxHeapify(1);
    }

    int getMax() {
        if(size == 0) return -1;
        return arr[1];
    }
};

// Function to find k-th smallest element
int kthSmallest(int arr[], int n, int k) {
    MaxHeap heap(k); // heap of size k

    // Step 1: Insert first k elements
    for(int i = 0; i < k; i++)
        heap.insert(arr[i]);

    // Step 2: Process remaining elements
    for(int i = k; i < n; i++) {
        if(arr[i] < heap.getMax()) {
            heap.removeMax();  // remove largest
            heap.insert(arr[i]); // insert current element
        }
    }

    return heap.getMax(); // root = k-th smallest
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    cout << "The " << k << "-th smallest element is: "
         << kthSmallest(arr, n, k) << endl;

    return 0;
}
