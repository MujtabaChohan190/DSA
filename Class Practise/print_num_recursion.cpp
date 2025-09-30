#include <iostream>
using namespace std;

void printNums(int n) { //n=1
    if(n == 1) {
        cout << "\n";
        return;
    }

    cout << n << " ";
    printNums(n-1);
}

int main() {
    printNums(100);
    return 0;
}
