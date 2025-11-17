#include <iostream>
#include <algorithm>
using namespace std;

struct Node {

    int value;
    int freq;
};
class MaxHeap {
public:
    Node *arr;
    int size;
    int capacity;

    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new Node[capacity + 1];
        arr[0].value = -1; 
        arr[0].freq = -1;
    }
    void heapifyUp(int index) {
        while (index > 1) {
            int parent = index / 2;
            if (arr[index].freq > arr[parent].freq ||
               (arr[index].freq == arr[parent].freq && arr[index].value > arr[parent].value)) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int left, right, largest;
        while (true) {
            left = 2 * index;
            right = 2 * index + 1;
            largest = index;

            if (left <= size && (arr[left].freq > arr[largest].freq || (arr[left].freq == arr[largest].freq && arr[left].value > arr[largest].value))) {
                largest = left;
            }
            if (right <= size && (arr[right].freq > arr[largest].freq ||(arr[right].freq == arr[largest].freq && arr[right].value > arr[largest].value))) {
                largest = right;
            }
            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else break;
        }
    }

    void insert(Node x) {
        if (size >= capacity) return;
        arr[++size] = x;
        heapifyUp(size);
    }
    Node extractMax() {
        if (size == 0) return {-1, -1};
        Node maxNode = arr[1];
        arr[1] = arr[size--];
        heapifyDown(1);
        return maxNode;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter k: ";
    cin >> k;
    Node freqArr[n];
    int freqSize = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < freqSize; j++) {
            if (freqArr[j].value == arr[i]) {
                freqArr[j].freq++;
                found = true;
                break;
            }
        }
        if (!found) {
            freqArr[freqSize].value = arr[i];
            freqArr[freqSize].freq = 1;
            freqSize++;
        }
    }
    MaxHeap heap(freqSize);
    for (int i = 0; i < freqSize; i++) {
        heap.insert(freqArr[i]);
    }
    cout << "Top " << k << " elements: ";
    for (int i = 0; i < k; i++) {
        Node top = heap.extractMax();
        if (top.value != -1)
            cout << top.value << " ";
    }
    cout << endl;
    return 0;
}
