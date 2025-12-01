#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {

  int h = 1;
  while (h < n/3)
  {
    h = 3*h+1;
  }
  while(h >= 1)
{
  
  for(int i = h ; i < n; i++)
  {
    int temp = arr[i];
    int j = i;
    while (j >= h && arr[j - h] > temp)
    {
        arr[j] = arr[j - h];
        j -= h;
    }
    arr[j] = temp;
  }

  h = (h - 1)/3;
  }  
}
int main() {
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    shellSort(arr, n);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
