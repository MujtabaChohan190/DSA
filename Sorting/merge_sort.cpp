#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid); // left half
        mergeSort(arr, mid + 1, end); // right half
        merge(arr, st, mid, end);
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size() - 1);

    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


-------------------------------------------------------------------------

#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end) {
    int temp[1000]; // temporary array (size should be >= original array size)
    int i = st, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int x = 0; x < k; x++) {
        arr[st + x] = temp[x];
    }
}

void mergeSort(int arr[], int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main() {
    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

