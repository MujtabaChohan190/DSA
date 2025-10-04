#include <iostream>
using namespace std;

class Team {
public:
    string name;
    int goals;
};

// Selection sort (array-style) on Team array by goals (ascending)
void selectionSortTeams(Team arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].goals < arr[min_index].goals) {
                min_index = j;
            }
        }
        // swap arr[i] and arr[min_index]
        Team temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Binary Search on teams array (sorted by goals)
int binarySearch(Team arr[], int n, int key) {
    int left = 0;           // first index
    int right = n - 1;      // last index

    while (left <= right) {
        int mid = left + (right - left) / 2;  // middle index

        if (arr[mid].goals == key) {
            return mid;   // found, return index
        }
        else if (arr[mid].goals < key) {
            left = mid + 1;   // search in right half
        }
        else {
            right = mid - 1;  // search in left half
        }
    }

    return -1;   // not found
}

int main() {
    Team teams[] = {
        {"Italy", 28},
        {"Brazil", 34},
        {"Argentina", 30},
        {"Germany", 29},
        {"Spain", 27},
        {"France", 31}
    };

    int n = sizeof(teams) / sizeof(teams[0]);

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << teams[i].name << " - " << teams[i].goals << endl;
    }

    // Sort using selection sort (not bubble sort)
    selectionSortTeams(teams, n);

    cout << "\nAfter sorting (by goals ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << teams[i].name << " - " << teams[i].goals << endl;
    }

    int searchGoals;
    cout << "\nEnter goal count to search: ";
    cin >> searchGoals;

    int index = binarySearch(teams, n, searchGoals);
    if (index != -1) {
        cout << "Team found: " << teams[index].name 
             << " (" << teams[index].goals << " goals)\n";
    }
    else {
        cout << "No team found with " << searchGoals << " goals.\n";
    }

    return 0;
}

