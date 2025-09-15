#include <iostream>
using namespace std;

void combSort(int arr[], int n) {
    float shrink = 1.3;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;
        //gapped bubble sort
        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}

int main() {
    int prices[] = {12000, 8000, 15000, 7000, 20000, 10000, 9000, 18000};
    int n = 8;

    combSort(prices, n);

    cout << "Cheapest 3 flights: ";
    for (int i = 0; i < 3; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;

    return 0;
}
