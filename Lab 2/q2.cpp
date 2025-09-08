#include <iostream>
using namespace std;

int main() {
    const int totalItems = 20;
    int stock[totalItems];

    cout << "Enter stock for 20 items:\n";
    for (int i = 0; i < totalItems; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> stock[i];
    }

    int itemNo, soldQty;
    cout << "\nEnter item number (1-20) to sell (0 to exit): ";
    cin >> itemNo;

    while (itemNo != 0) {
        if (itemNo < 1 || itemNo > totalItems) {
            cout << "Invalid item!\n";
        } else {
            cout << "Quantity sold: ";
            cin >> soldQty;

            if (soldQty > stock[itemNo - 1]) {
                cout << "Only " << stock[itemNo - 1] << " left.\n";
            } else {
                stock[itemNo - 1] = stock[itemNo - 1] - soldQty;
                cout << "Remaining stock of item" << itemNo<<"is: "
                     << stock[itemNo - 1] << endl;
            }
        }
        cout << "\nEnter item number (1-20) to sell (0 to exit): ";
        cin >> itemNo;
    }

    cout << "\nFinal stock:\n";
    for (int i = 0; i < totalItems; i++) {
        cout << "Item " << i + 1 << ": " << stock[i] << endl;
    }

    return 0;
}
