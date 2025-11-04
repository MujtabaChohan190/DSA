/* TIME COMPLEXITY: O(d * (n + k))
   - where d = number of digits, k = range of digits (0–9)
* SPACE COMPLEXITY: O(n + k) (for count and output arrays)
* STABILITY: Stable - Uses counting sort for each digit, preserving order of equal elements.
1️⃣ Find the maximum number to know the total digits (d).
2️⃣ Apply counting sort for each digit (ones, tens, hundreds...).
3️⃣ Use cumulative count array to place elements in correct order after each pass.*/




#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n]; //n is the original array count 
    int count[10] = {0};

    // Count digits - we count the frequency of each digit here 
    for(int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;   // extract digit
        count[digit]++;
    }

    // Convert count into cumulative count - It helps determine the final position (index) of each element in the output array.
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (from right to left for stability)
    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;   // extract digit again
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output to original
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxNumber = getMax(arr, n);

    // Apply counting sort for each digit place
    for(int exp = 1; maxNumber / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    //count of original array
    int n;
    cout << "Enter number of employee IDs: ";
    cin >> n;
    int arr[n];
    //inputting data in array
    cout << "Enter employee IDs:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted IDs:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
