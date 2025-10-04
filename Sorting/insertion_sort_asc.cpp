#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }
}

int main() {
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};
    selectionSort(arr, n); // Note: This line in the image likely intends to call insertionSort
    printArray(arr, n);
}
