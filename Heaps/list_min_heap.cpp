#include <iostream>
using namespace std;

struct Node {
    int value;   
    int arrIndex;  
    int elemIndex; 
};
class MinHeap {
public:
    Node* heap;
    int size;

    MinHeap(int capacity) {
        heap = new Node[capacity];
        size = 0;
    }
    ~MinHeap() {
        delete[] heap;
    }
    void swap(Node &a, Node &b) {
        Node temp = a;
        a = b;
        b = temp;
    }
    void insert(Node n) {
        heap[size] = n;
        int i = size;
        size++;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent].value > heap[i].value) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }
    Node getMin() {
        return heap[0];
    }
    void removeMin() {
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
    void heapifyDown(int i) {
        while (true) {
            int smallest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < size && heap[left].value < heap[smallest].value)
                smallest = left;
            if (right < size && heap[right].value < heap[smallest].value)
                smallest = right;

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else break;
        }
    }
};

int main() {
    int k = 3;
    int sizes[k] = {4, 3, 5};
    int server1[] = {1,  5,  9, 14};
    int server2[] = {2,  6,  10};
    int server3[] = {3,  4,  8, 11, 15};
    int* servers[k] = {server1, server2, server3};
    int totalSize = 0;
    for (int i = 0; i < k; i++)
        totalSize += sizes[i];
    int* merged = new int[totalSize];
    MinHeap mh(k);
    for (int i = 0; i < k; i++) {
        Node n;
        n.value = servers[i][0];
        n.arrIndex = i;
        n.elemIndex = 0;
        mh.insert(n);
    }
    int mergedIndex = 0;
    while (mh.size > 0) {
        Node current = mh.getMin();
        mh.removeMin();
        merged[mergedIndex++] = current.value;
        int arrID = current.arrIndex;
        int nextIndex = current.elemIndex + 1;
        if (nextIndex < sizes[arrID]) {
            Node newNode;
            newNode.value = servers[arrID][nextIndex];
            newNode.arrIndex = arrID;
            newNode.elemIndex = nextIndex;
            mh.insert(newNode);
        }
    }
    cout << "Merged Sorted Patient Records:\n";
    for (int i = 0; i < totalSize; i++)
        cout << merged[i] << " ";

    delete[] merged;
    return 0;
}
