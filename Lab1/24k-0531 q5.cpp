
/*  CODE WITHOUT ASSIGNMENT AND COPY CONSTRUCTOR
#include<iostream>
#include<cstring>
using namespace std;

class Teacher{
    public:
    char* name;
    char* subject;
    int exp;
    
    Teacher(char* n, char* s , int e){
        name = new char[strlen(n)+1];
        strcpy(name , n);
        subject = new char[strlen(s)+1];
        strcpy(subject , s);
        exp = e;
    }

    ~Teacher(){
        delete[] name;
        delete[] subject;
    }

    void display() const{
        cout<<"Name"<<name<<"subject"<<subject<<"Experience"<<exp<<endl;

    }

};

int main(){
    cout<<"Checking without rule of three"<<endl;
    {
      Teacher obj1("san" , "English" , 4);
      Teacher obj2 = obj1; //Shallow copy happens here

      obj1.display();
      obj2.display();

    }

    //As this block ends , the destructors for t2 and t1 will be called due to which both will try to delete the same memory resulting in code crash

    return 0;    
}
*/

#include<iostream>
#include<cstring>
using namespace std;

class Teacher{
    public:
    char* name;
    char* subject;
    int exp;
    
    Teacher(char* n, char* s , int e){
        name = new char[strlen(n)+1];
        strcpy(name , n);
        subject = new char[strlen(s)+1];
        strcpy(subject , s);
        exp = e;
    }

    Teacher (const Teacher& other){
        name = new char[strlen(other.name) + 1];
        strcpy(name , other.name);
        subject = new char[strlen(other.subject) + 1];
        strcpy(subject , other.subject);
        exp = other.exp;
    }

    Teacher& operator=(const Teacher& other){
        if(this!= &other){
            delete[] name; // Free previously allocated memory to avoid memory leaks 
            //t2 = t1 ; t2 already had name and subject space allocated but when we deep copy t1 , we would be simply overwriting the pointers , due to which the old memory would be lost forever due to memory leak
            // (otherwise we lose access to previously allocated blocks)
            delete[] subject;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            subject = new char[strlen(other.subject) + 1];
            strcpy(subject, other.subject);

            exp= other.exp;
        }
        return *this;
        
    }

    ~Teacher(){
        delete[] name;
        delete[] subject;
    }

    void display() const{
        cout<<"Name"<< name<<"subject"<< subject<<"Experience"<< exp<<endl;

    }

};

int main() {

    cout << " With Rule of Three "<< endl;
    Teacher t1("Ali", "Math", 10);
    Teacher t2 = t1;   // Deep copy constructor

    cout << "Teacher 1: ";
    t1.display();
    cout << "Teacher 2 (copied): ";
    t2.display();

    Teacher t3("Sara", "Physics", 5);
    cout << "Before assignment -> Teacher 3: ";
    t3.display();

    t3 = t1; // Deep assignment
    cout << "After assignment -> Teacher 3: ";
    t3.display();

    return 0;
}