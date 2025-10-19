#include <iostream>
using namespace std;

#define SIZE 5

class QueueArray {
    int arr[SIZE];
    int front, rear;

public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if (isFull()) cout << "Queue Overflow\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
            cout << "Customer " << x << " added to queue.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue Underflow\n";
        else {
            cout << "Customer " << arr[front] << " served and removed from queue.\n";
            front++;
        }
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Current Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    QueueArray q;
    int choice, id;

    do {
        cout << "\n--- Ticket Counter Menu ---\n";
        cout << "1. Add Customer to Queue (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. View First Customer\n";
        cout << "4. Display All Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer ID: ";
                cin >> id;
                q.enqueue(id);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                id = q.Front();
                if (id != -1)
                    cout << "Next customer to be served: " << id << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
