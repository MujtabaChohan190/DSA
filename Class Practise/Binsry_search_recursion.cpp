#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // helper recursive binary search
    int binSearch(vector<int>& arr, int tar, int st, int end) {
        if (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == tar) return mid;
            else if (arr[mid] < tar) {
                return binSearch(arr, tar, mid + 1, end);
            } else {
                return binSearch(arr, tar, st, mid - 1);
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int tar) {
        return binSearch(arr, tar, 0, arr.size() - 1);
    }
};

int main() {
    Solution obj;
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target;

    cout << "Enter target element: ";
    cin >> target;

    int result = obj.search(arr, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
