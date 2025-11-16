#include <bits/stdc++.h>
using namespace std;

void heapifymax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifymax(arr, n, largest);
    }
}

void mergeHeaps(int h1[], int n1, int h2[], int n2, int merged[], int &mSize) {
    mSize = n1 + n2;

    for (int i = 1; i <= n1; i++)
        merged[i] = h1[i];

    for (int i = 1; i <= n2; i++)
        merged[n1 + i] = h2[i];

    for (int i = mSize / 2; i >= 1; i--)
        heapifymax(merged, mSize, i);
}

int main() {
    int h1[6] = {0, 50, 30, 40, 10, 20};
    int h2[5] = {0, 45, 35, 25, 15};

    int merged[20];
    int mergedSize;

    mergeHeaps(h1, 5, h2, 4, merged, mergedSize);

    for (int i = 1; i <= mergedSize; i++)
        cout << merged[i] << " ";
}
