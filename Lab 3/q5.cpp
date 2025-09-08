#include<iostream>
using namespace std;

class Node{
	public:
	string status;
	Node* next;
	Node(string stat):status(stat){
		next=NULL;
	}
};

class Singlylist{
	Node* head;
	Node* tail;
	public:
		Singlylist(){
			head=NULL;
			tail=NULL;
		}
		void insertNode(string stat){
			Node* newNode=new Node(stat);
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}
			tail->next=newNode;
			tail=newNode;
		}
		void vipCustomer(string stat){
			Node* newNode=new Node(stat);
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}
			newNode->next=head;
			head=newNode;
		}
		
		void removeCustomer(){
			Node* temp=head;
			Node* prev=NULL;
			int count=0;
		    while (temp != NULL) {
	        if (temp->status == "purchased") {
	            count++;
	            if (temp == head) {   //CASE 1: DELETING HEAD
	                head = head->next;
	                delete temp;
	                temp = head;
	                if (head == NULL) { //IT IS CHECKING THAT AFTER THE DELETION OF HEAD , IS HEAD NOW NULL , IF ITS NULL , SO WE ALSO MAKE TAIL NULL
	                    tail = NULL;
	                }
	            }
	            else {
	                prev->next = temp->next; //CASE 2: Deletion from tail-in this case we know that the node to delete is not head , so we bypass the head node through this
	                if (temp == tail) {
	                    tail = prev;
	                }
	                delete temp;
	                temp = prev->next;
	            }
	        } else {
	            prev = temp;
	            temp = temp->next;
	        }
	    }
	    cout << "Total " << count << " customers are removed" << endl;
	}
};

int main(){
	
	Singlylist s1;
	s1.insertNode("buying");
	s1.insertNode("buying");
	s1.insertNode("purchased");
	s1.insertNode("buying");
	s1.vipCustomer("purchased");
	s1.insertNode("purchased");
	s1.removeCustomer();
}
