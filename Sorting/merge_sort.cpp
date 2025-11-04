/* TIME COMPLEXITY IN ALL CASES IS O(n LOGN)
   SPACE COMPLEXITY IS O(N) TAKES AUXILARYSPACE IN FORM OF TEMP VARIABE
   STABLE - PRESERVES THE ORDER OF EQUAL ELEMENTS - Merge Sort is stable because when equal elements are compared, it copies the element from the left subarray first, preserving their original order.
1️⃣ Divide the array into two halves until each part has one element.
2️⃣ Sort & Merge the halves by comparing elements into a temporary array.
3️⃣ Copy back the merged (sorted) result into the original array */

#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end) {
    int temp[1000]; // temporary array (size should be >= original array size)
    int i = st, j = mid + 1, k = 0;
//in this step , we are checking the smallest values between two sorted arrays which are backtracked and now need to be combined
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
//there could be a case that j pointer array which is second array gets empty after inserting all its elements to temp , so i could be left so hum bachiwi values ko dalenge
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int x = 0; x < k; x++) {
        arr[st + x] = temp[x]; //our temp start index is 0 but in origiinal array sotted position starts at index - to ensure we place the combined array correctly in sorted  order in orgiianl array we do this
    }
}

void mergeSort(int arr[], int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);//left - divide left 
        mergeSort(arr, mid + 1, end);//right 
        merge(arr, st, mid, end);//combine left and right 
    }
}

int main() {
    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {  //getting sorted array
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

