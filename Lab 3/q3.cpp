#include<iostream>
using namespace std;

class Node{
	public:
	string Seatstatus;
	Node* next;
	Node(string stat){
		Seatstatus = stat;
		next = NULL;
	}
};

class CircularList{
	Node* head;
	Node* tail;
public:
	CircularList(){
		head = tail = NULL;
		
	}
	
	//Inserting seat vacancy as empty or reserved
	void insertSeat(string stat){
		Node* n = new Node(stat);
		if(head == NULL){
			head = tail = n;
			tail->next = n;
		}else{
			tail->next = n;
			tail = n;
			tail->next = head;
		}
		
	}
	
	//Checking the availability of seats by counting empty seats
	void checkStatus(){
		if(head==NULL){
        cout<<"No seats available\n";
        return;
    }
    Node* temp=head;
    int count=0;

    do {
        if(temp->Seatstatus == "empty") {
            count++;
        }
        temp=temp->next;
    }while(temp!=head);

    cout << "Total "<<count<< " seats are available" << endl;
	}
	
};

int main(){
	
    CircularList coach;

    coach.insertSeat("empty");
    coach.insertSeat("reserved");
    coach.insertSeat("empty");
    coach.insertSeat("reserved");
    coach.insertSeat("empty");

    coach.checkStatus();

    return 0;
}
