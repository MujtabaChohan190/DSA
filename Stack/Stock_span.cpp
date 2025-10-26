#include <iostream>
#include <stack>
using namespace std;

int main() {
    // stock prices (array)
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);

    // answer array
    int ans[n];

    stack<int> s;

    for(int i = 0; i < n; i++) {

        // keep same style condition
        while(s.size() > 0 && price[s.top()] <= price[i]) {
            s.pop();
        }

        if(s.size() == 0) {
            ans[i] = i + 1;
        } 
        else {
            ans[i] = i - s.top();
        }

        s.push(i);
    }

    // print result using normal for loop
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
