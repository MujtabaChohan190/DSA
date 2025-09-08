#include<iostream>
using namespace std;

class Node{
	public:
	float trasaction;
	Node* next;
	Node* prev;
	Node(float tras):trasaction(tras){
		next=NULL;
		prev=NULL;
	}
};

class Doublylist{
	Node* head;
	Node* tail;
	public:
		Doublylist(){
			head=NULL;
			tail=NULL;
		}
		void insertTrasaction(float dat){
			Node* newNode=new Node(dat);
			if(head==NULL){
				head=newNode;
				tail=newNode;
				
			}
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}
		
		void traverse(){
			Node* back=tail;
			Node* forw=head;
			string ch;
			cout<<"Enter forward,backward or 0 :";
			do{
				cin>>ch;
				if(ch=="forward"){
					cout<<"The trasaction on forward tereversal is: "<<forw->trasaction<<endl;
					forw=forw->next;
				}
				else if(ch=="backward"){
					cout<<"The trasaction on backward tereversal is: "<<back->trasaction<<endl;
					back=back->prev;
				}
				else if(ch=="0"){
					break;
				}
				cout<<"Enter Again"<<endl;
			}while(back->prev!=NULL || forw->next!=NULL );
		}
};

int main(){
	Doublylist d1;
	d1.insertTrasaction(1234.2);
	d1.insertTrasaction(4321.2);
	d1.insertTrasaction(542.1);
	d1.insertTrasaction(76533.2);
	d1.traverse();
}
