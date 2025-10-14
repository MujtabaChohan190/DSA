#include <iostream>
#include <string>
using namespace std;

struct PrintJob {
    int jobID;
    int pages;
};

class PrinterQueue {
private:
    PrintJob* queue;
    int front;
    int rear;
    int maxSize;
    int count;

public:
    PrinterQueue(int size) : front(0), rear(-1), maxSize(size), count(0) {
        queue = new PrintJob[maxSize];
    }

    ~PrinterQueue() {
        delete[] queue;
    }

    bool isFull() const {
        return count == maxSize;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void enqueue(int jobID, int pages) {
        if (isFull()) {
            cout << "Queue is full. Cannot add new job.\n";
            return;
        }
        rear = (rear + 1) % maxSize;
        queue[rear].jobID = jobID;
        queue[rear].pages = pages;
        count++;
        cout << "Job " << jobID << " with " << pages << " pages added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No job to process.\n";
            return;
        }
        PrintJob job = queue[front];
        front = (front + 1) % maxSize;
        count--;
        cout << "Job " << job.jobID << " completed and removed from the queue.\n";
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current print queue:\n";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << "Job ID: " << queue[idx].jobID << ", Pages: " << queue[idx].pages << "\n";
            idx = (idx + 1) % maxSize;
        }
    }
};

int main() {
    int maxJobs;
    cout << "Enter max size of print queue: ";
    cin >> maxJobs;

    PrinterQueue pq(maxJobs);

    int choice;
    do {
        cout << "\n1. Add Print Job\n2. Complete Print Job\n3. Show Queue\n4. Exit\nChoose option: ";
        cin >> choice;

        if (choice == 1) {
            int id, pages;
            cout << "Enter Job ID: ";
            cin >> id;
            cout << "Enter Number of Pages: ";
            cin >> pages;
            pq.enqueue(id, pages);
        }
        else if (choice == 2) {
            pq.dequeue();
        }
        else if (choice == 3) {
            pq.display();	
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
