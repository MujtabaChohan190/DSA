#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Declare array
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Answer array
    int ans[n];

    stack<int> s;

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--) {

        // Pop elements smaller or equal to current
        while(s.size() > 0 && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack empty → no greater element to the right
        if(s.size() == 0) {
            ans[i] = -1;
        }
        else {
            ans[i] = s.top();
        }

        // Push current element into stack
        s.push(arr[i]);
    }

    // Print result
    cout << "Next Greater Elements: ";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
