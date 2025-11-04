/*Write the code to use Quicksort to find the median of an unsorted array without necessarily sorting 
all the elements. Explain the logic of your code separately.
1️⃣ We use the partition logic from QuickSort.

It puts the pivot in its correct sorted position.

Elements smaller than pivot go to the left, larger go to the right.

2️⃣ Instead of sorting both halves (like QuickSort does),

we check where the pivot lands (pivIdx).

3️⃣ If pivot is at the median index (n/2) → that’s our answer!

If pivot index is greater than median, search left half.

If pivot index is less than median, search right half.

4️⃣ This avoids unnecessary sorting — only partially partitions the array.*/


#include <iostream>
using namespace std;

// Partition function (same as QuickSort)
int partition(int arr[], int st, int end) {
    int pivot = arr[end];
    int idx = st - 1;

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }

    idx++;
    int temp = arr[end];
    arr[end] = arr[idx];
    arr[idx] = temp;

    return idx; // pivot's correct position
}

// Quickselect: finds the k-th smallest element (not fully sorted)
int quickSelect(int arr[], int st, int end, int k) {
    if (st <= end) {
        int pivIdx = partition(arr, st, end);

        if (pivIdx == k)          // pivot is the k-th smallest
            return arr[pivIdx];
        else if (pivIdx > k)      // median lies in left part
            return quickSelect(arr, st, pivIdx - 1, k);
        else                      // median lies in right part
            return quickSelect(arr, pivIdx + 1, end, k);
    }
    return -1; // should not reach here
}

int main() {
    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    int medianIndex = n / 2;
    int median = quickSelect(arr, 0, n - 1, medianIndex);

    cout << "Median: " << median << endl;
    return 0;
}
