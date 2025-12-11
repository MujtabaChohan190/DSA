#include <iostream>
using namespace std;

class heap
{
public:
    int *arr;
    int capacity;
    int size;

    heap(int cap):capacity(cap),size(0)
    {
        arr = new int[capacity];
        arr[0] = -1;
    }

    void insertMin(int val)
    {
        if(size == capacity - 1) return;
        size++;
        int idx = size;
        arr[idx] = val;
        while(idx > 1)
        {
            int parent = idx / 2;
            if(arr[parent] > arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else return;
        }
    }

    void minHeapify(int i)
    {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= size && arr[left] < arr[smallest])
            smallest = left;
        if(right <= size && arr[right] < arr[smallest])
            smallest = right;

        if(smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    void deleteMin()
    {
        if(size == 0) return;
        arr[1] = arr[size];
        size--;
        minHeapify(1);
    }

    int top()
    {
        return arr[1];
    }
};

int kthLargestSubarraySums(int arr[], int n, int k)
{
    heap h(k+1);

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            if(h.size < k)
                h.insertMin(sum);
            else if(sum > h.top())
            {
                h.deleteMin();
                h.insertMin(sum);
            }
        }
    }

    return h.top(); // k-th largest sum
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << "The " << k << "-th largest subarray sum is: " 
         << kthLargestSubarraySums(arr, n, k) << endl;
}
