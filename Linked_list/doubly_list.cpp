#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node* prev;
		Node(int d){
			data=d;
			next=NULL;
			prev=NULL;
		}
};

class DoublyList{
	Node* head;
	Node* tail;
	public:
		DoublyList(){
			head=NULL;
			tail=NULL;
		}
		void insertEnd(int d){
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				tail=newNode;
				return;
			}
			newNode->prev=tail;
			tail->next=newNode;
			tail=newNode;
		}
		void insertStart(int d){
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				tail=newNode;
				return;
			}
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
		void insertMiddle(int d){
			int pos;
			int count=0;
			Node* newNode=new Node(d);
			cout<<"Enter index position: ";
			cin>>pos;
			Node* temp=head;
			while(temp!=NULL){
				if(count==pos-1){
					newNode->prev=temp;
					newNode->next=temp->next;
					temp->next->prev=newNode;
					temp->next=newNode;
					return;
				}
				temp=temp->next;
				count++;
			}
		}
		void deleteStart(){
			Node* temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
		}
		void deleteEnd(){
			Node* temp=tail;
			tail=tail->prev;
			tail->next=NULL;
			delete temp;
		}
		void deleteMiddle(){
			int pos;
			int count=0;
			Node* temp=head;
			cout<<"Enter index position: ";
			cin>>pos;
			while(temp!=NULL){
				Node* prev;
				if(count==pos){
					prev->next=temp->next;
					temp->next->prev=prev;
					delete temp;
					return;
				}
				prev=temp;
				temp=temp->next;
				count++;
			}
		}
		void printNode(){
			Node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl<<endl;
		}
		void insertionSort(){
			Node* temp=head;
			temp=temp->next;
			while(temp!=NULL){
				Node* previous=temp->prev;
				int num=temp->data;
				Node* mov=temp;
				while(previous!=NULL && previous->data>num){
					mov->data=previous->data;
					mov=mov->prev;
					previous=previous->prev;
				}
				mov->data=num;
				temp=temp->next;
			}
		}
};

int main(){
	DoublyList s1;
	s1.insertEnd(11);
	s1.insertEnd(21);
	s1.insertEnd(3);
	s1.insertEnd(73);
	s1.insertEnd(10);
	s1.insertStart(91);
	s1.printNode();
	s1.insertionSort();
	s1.printNode();
	
//	s1.deleteMiddle();
//	s1.printNode();
//	s1.deleteEnd();
//	s1.printNode();
//	s1.deleteStart();
//	s1.printNode();
}
