#include<iostream>
using namespace std;

class Node{
	public:
	string web;
	Node* next;
	Node* prev;
	
	Node(string val){
		web = val;
		next = NULL;
		prev = NULL;
	}
};

class Doublylist{
	Node* head;
	Node* tail;
	
public:	   //remember to put it always  
	Doublylist(){
		head = NULL;
		tail = NULL;
	}
	//Inserting new websites
	void InsertEnd(string web){
		Node* n = new Node(web);
		if(head == NULL){
			head = tail = n;
		}else{
			tail->next = n;
			n->prev = tail;
			tail = n;
		}		
	}
	//Traverse Forward 
	void TraverseForward(){
	   if(head == NULL){
	   	cout<<"No websites available"<<endl;
	   	return;
	   }
       Node* temp = head;
       cout << "History Forward: ";
       while (temp != NULL) {
        cout << temp->web << " ";
        temp = temp->next;
       }    
       cout << endl;
    }   
    //Traverse Backward
    void TraverseBackward(){
    	if(tail == NULL){
    		cout<<"No websites available"<<endl;
		}
    	Node* temp = tail;
    	cout<<"History Backward: ";
    	while(temp!=NULL){
    		cout<<temp->web<<" ";
    		temp = temp->prev;
		}
		cout<<endl;
	}
	//Searching websites in history
	bool Search(string url){
		Node* temp = head;
		while(temp->next != NULL){
			if(temp->web == url){
				cout<<"Website found: "<<temp->web<<endl;
				return true;
			}
			temp =  temp->next;			
		}
		cout<<"Website not found in history";
		return false;
	}
	
};

int main() {
    Doublylist history;

    history.InsertEnd("Google");
    history.InsertEnd("YouTube");
    history.InsertEnd("Facebook");
    history.InsertEnd("Twitter");

    history.TraverseForward();
    history.TraverseBackward();

    history.Search("YouTube");
    history.Search("LinkedIn");

    return 0;
}


}
