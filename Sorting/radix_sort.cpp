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
    int output[n];
    int count[10] = {0};

    // Count digits
    for(int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;   // extract digit
        count[digit]++;
    }

    // Convert count into cumulative count
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
    int n;
    cout << "Enter number of employee IDs: ";
    cin >> n;

    int arr[n];
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
