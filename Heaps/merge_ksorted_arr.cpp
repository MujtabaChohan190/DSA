#include <iostream>
using namespace std;

struct Node {
    int value;
    int arrIdx;
    int elemIdx;
};

// ----------- Custom Min Heap --------------
class MinHeap {
public:
    Node *heap;
    int size;
    int capacity;

    MinHeap(int cap) {
        heap = new Node[cap];
        size = 0;
        capacity = cap;
    }

    void swapNodes(Node &a, Node &b) {
        Node temp = a;
        a = b;
        b = temp;
    }

    void insert(Node x) {
        if (size == capacity) return;

        heap[size] = x;
        int i = size;
        size++;

        // bubble up
        while (i != 0) {
            int parent = (i - 1) / 2;
            if (heap[parent].value > heap[i].value) {
                swapNodes(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    Node extractMin() {
        Node root = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapify(0);

        return root;
    }

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left].value < heap[smallest].value)
            smallest = left;

        if (right < size && heap[right].value < heap[smallest].value)
            smallest = right;

        if (smallest != i) {
            swapNodes(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    bool empty() {
        return size == 0;
    }
};

// --------------------------------------------
//        Merge k Sorted Arrays (No vector)
// --------------------------------------------

int* mergeKSortedArrays(int arr[][100], int k, int sizes[], int &totalSize) {

    // Calculate total size of final merged array
    totalSize = 0;
    for (int i = 0; i < k; i++)
        totalSize += sizes[i];

    int *result = new int[totalSize];

    // Min-heap capacity = k (1 element from each array at a time)
    MinHeap heap(k);

    // Step 1: Insert first element of each sorted array
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            Node n;
            n.value = arr[i][0];
            n.arrIdx = i;
            n.elemIdx = 0;
            heap.insert(n);
        }
    }

    // Step 2: Extract min, push next element from same array
    int index = 0;
    while (!heap.empty()) {
        Node top = heap.extractMin();

        // Store popped value
        result[index++] = top.value;

        int nextIndex = top.elemIdx + 1;

        // Insert next element of same array (if exists)
        if (nextIndex < sizes[top.arrIdx]) {
            Node nextNode;
            nextNode.value = arr[top.arrIdx][nextIndex];
            nextNode.arrIdx = top.arrIdx;
            nextNode.elemIdx = nextIndex;
            heap.insert(nextNode);
        }
    }

    return result;
}

// --------------------------------------------
//                   MAIN
// --------------------------------------------

int main() {
    // Example: k = 3 arrays
    int k = 3;

    int arr[3][100] = {
        {1, 4, 9},
        {2, 3, 8},
        {5, 6, 7}
    };

    int sizes[3] = {3, 3, 3};

    int totalSize;
    int *merged = mergeKSortedArrays(arr, k, sizes, totalSize);

    cout << "Merged Array: ";
    for (int i = 0; i < totalSize; i++)
        cout << merged[i] << " ";

    delete[] merged;

    return 0;
}
