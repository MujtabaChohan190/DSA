#include<iostream>
using namespace std;

class Book{
	public:
	string title;
	string author;
	float price;
	
	Book(){
		title= "unknown title";
		author = "unkown author";
		price = 0.0;
		
	}
	//Parameterized Constructor 
	Book(string t , string a , float p){
		title = t;
		author = a;
		price = p;		
	}
	
	//copy constructor 
	Book(const Book &b){
		title = b.title;
		author = b.author;
		price = b.price;
	}
	
	//= assignment operator
	Book& operator=(const Book &b){
		if (this!=&b){
			title = b.title;
			author = b.author;
			price = b.price;
		}
		return *this;
	}
	//Destructor
	~Book(){
		cout<<"Destructor called for book:"<<title<<endl;		
	}
		
};

int main(){
	Book obj1; //brackets are not needed here 
	Book obj2("Sherlock Holmes","Hemming",20.0);
	Book obj3 = obj2; //Book b3(b2)	
	return 0;
};
