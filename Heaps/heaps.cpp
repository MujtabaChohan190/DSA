#include<iostream>
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
        arr[0] = -1; // for 1-based indexing
    }

    // -------- MAX HEAP INSERTION --------
    void insert(int val)
    {
        if(size == capacity - 1) return;
        size++;
        int idx = size;
        arr[idx] = val;

        // Heapify Up (Max Heap)
        while(idx > 1)
        {
            int parent = idx / 2;
            if(arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
                return;
        }
    }
     // -------- MAX HEAPIFY (downward) --------
    void maxHeapify(int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= size && arr[left] > arr[largest])
            largest = left;
        if(right <= size && arr[right] > arr[largest])
            largest = right;

        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);            
        }
    }

    // -------- MAX HEAP DELETION --------
    void deleteNode()
    {
        if(size == 0)
        {
            cout << "Empty heap" << endl;
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];
        // Step 2: Reduce heap size
        size--;

        // Step 3: Heapify down (Max Heap)
       maxHeapify(1);
    }

    // -------- MIN HEAP INSERTION --------
    void insertMin(int val)
    {
        if(size == capacity - 1) return;
        size++;
        int idx = size;
        arr[idx] = val;

        // Heapify Up (Min Heap) - in min heap parent should be smallest so we check if its not greater
        while(idx > 1)
        {
            int parent = idx / 2;
            if(arr[parent] > arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
                return;
        }
    }
    
 // -------- MIN HEAPIFY (downward) --------
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
    // -------- MIN HEAP DELETION --------
    void deleteMin()
    {
        if(size == 0)
        {
            cout << "Empty heap" << endl;
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];
        // Step 2: Reduce heap size
        size--;

        // Step 3: Heapify down (Min Heap)
     minHeapify(1);
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// -------- HEAPIFY FUNCTIONS --------
void heapifymax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[left] > arr[largest])
        largest = left;
    if(right <= n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifymax(arr, n, largest);
    }
}

void heapifymin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[left] < arr[smallest])
        smallest = left;
    if(right <= n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapifymin(arr, n, smallest);
    }
}

// -------- HEAP SORT (MAX HEAP) --------
void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapifymax(arr, size, 1);
    }
}

int main()
{
    cout << "--- MAX HEAP ---" << endl;
    heap h1(100);
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();
    h1.deleteNode();
    h1.print();
    cout << "\n--- MIN HEAP ---" << endl;
    heap h2(100);
    h2.insertMin(50);
    h2.insertMin(55);
    h2.insertMin(53);
    h2.insertMin(52);
    h2.insertMin(54);
    h2.print();
    h2.deleteMin();
    h2.print();

    return 0;
}
