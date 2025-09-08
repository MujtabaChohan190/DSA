#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int dat):data(dat){
			next=NULL;
		}
};

class SinglyList{
	Node *head;
	Node *tail;
	public:
		SinglyList(){
			head=NULL;
			tail=NULL;
		}
		
		void insert(int data){
			Node *newNode=new Node(data);
			if(head==NULL){
				head=newNode;
				tail=newNode;
				return;
			}
			Node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newNode;
			tail=newNode;
		}
		
		void printNode(){
			Node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL";
		}	
};

int main(){
	SinglyList s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.printNode();
}
