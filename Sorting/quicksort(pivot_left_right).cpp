#include <iostream>
using namespace std;

int partition(int arr[], int st, int end) {
    int idx = st - 1;
    int pivot = arr[end];

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            // manual swap arr[j] and arr[idx]
            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }

    idx++;
    // manual swap arr[end] and arr[idx]
    int temp = arr[end];
    arr[end] = arr[idx];
    arr[idx] = temp;

    return idx;
}

void quickSort(int arr[], int st, int end) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);    // left side
        quickSort(arr, pivIdx + 1, end);  // right side
    }
}

int main() {
    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
