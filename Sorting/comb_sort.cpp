#include<iostream>
using namespace std;
void combSort(int arr[],int n)
{
    bool is_Swapped = true;
    int gap = n;
    while (gap > 1||is_Swapped)
    {
        gap = gap/1.3;
        if(gap<1)gap = 1;
        is_Swapped = false;
        for (int i = 0; i+gap < n; i++)
        {
            if(arr[i]>arr[i+gap])
            {
                swap(arr[i],arr[i+gap]);
                is_Swapped = true;
            }
        }
        
    }

    
}
int main()
{
    int arr[] = {5,1,6,4,2,3};
    int n = 6;
    combSort(arr,6);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
