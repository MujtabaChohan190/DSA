#include <iostream>
using namespace std;

class MinHeap {
public:
    int* arr;
    int capacity;
    int size;

    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity + 1]; // 1-based indexing
        arr[0] = -1; // dummy
    }

    ~MinHeap() {
        delete[] arr;
    }

    // -------- MIN HEAP INSERTION --------
    void insert(int val) {
        if(size == capacity) return; // heap full
        size++;
        int idx = size;
        arr[idx] = val;

        // Heapify Up
        while(idx > 1) {
            int parent = idx / 2;
            if(arr[parent] > arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            } else {
                return;
            }
        }
    }

    // -------- MIN HEAPIFY (downward) --------
    void minHeapify(int i) {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= size && arr[left] < arr[smallest])
            smallest = left;
        if(right <= size && arr[right] < arr[smallest])
            smallest = right;

        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    // -------- REMOVE ROOT (smallest) --------
    void removeMin() {
        if(size == 0) return;
        arr[1] = arr[size];
        size--;
        minHeapify(1);
    }

    int getMin() {
        if(size == 0) return -1;
        return arr[1];
    }
};

// -------- Find k-th largest using MinHeap --------
int kthLargest(int arr[], int n, int k) {
    MinHeap heap(k); // min heap of size k

    // Step 1: Insert first k elements
    for(int i = 0; i < k; i++)
        heap.insert(arr[i]);

    // Step 2: Process remaining elements
    for(int i = k; i < n; i++) {
        if(arr[i] > heap.getMin()) {
            heap.removeMin();   // remove smallest among k largest
            heap.insert(arr[i]);
        }
    }

    // Step 3: Root = k-th largest
    return heap.getMin();
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    cout << "The " << k << "-th largest element is: "
         << kthLargest(arr, n, k) << endl;

    return 0;
}
