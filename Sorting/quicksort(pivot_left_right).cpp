/* 
   TIME COMPLEXITY:
      - Best Case: O(n log n)
      - Average Case: O(n log n)
      - Worst Case: O(n²) (when pivot is always smallest/largest)
   
   SPACE COMPLEXITY: O(log n) due to recursive call stack (in-place, no extra array)
   Both merge sort and quicksort have same time complexity 
   STABLE OR NOT:
      - NOT STABLE — because swapping elements around the pivot can change 
        the order of equal elements.
   
   1️⃣ Choose a pivot element.
   2️⃣ Partition the array so that smaller elements go left, larger go right.
   3️⃣ Recursively apply Quick Sort on both sides of the pivot.
*/


#include <iostream>
using namespace std;

/*Partition function will choose pivot  and shift smaller elements to right and shift bigger 
elements to left from array 
This function will return the pivot index  it returns the rigghtful  position of pivot*/

int partition(int arr[], int st, int end) {
    int idx = st - 1;
    int pivot = arr[end];
//j var has work to iterate through whole array and compare all elements to pivot , index ka kaam hota hai lesser elements kailiye jaga banana 
    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            //we found an element which is smaller than pivot so we increase the idx and then later place arr[j] into that arr[idx]
            idx++;
            //swap(arr[j] , arr[idx])
            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }
    //by the end of this we have brough smaller elements to right and bigger elemetns to left ,but pivot correct position is still not decided 

    idx++;
    // swap( arr[end] , arr[idx])
    int temp = arr[end];
    arr[end] = arr[idx];
    arr[idx] = temp;

    return idx; //return pivot
}
//once we find pivot and shift left and right the values the original array through partition , we call quicksort for left and right blocks
void quickSort(int arr[], int st, int end) {
    if (st < end) { //for single element block , theres no need of quicksort , so algo should stop work when we have one element 
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
