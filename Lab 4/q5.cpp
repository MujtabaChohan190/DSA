#include <iostream>
using namespace std;

class Node
{
public:
    double data;
    Node *next;
    Node(double val) : data(val), next(NULL) {}
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = tail = NULL;
    }
    void push_back(double val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = NULL;
        }
    }
    void push_front(double val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insert(int pos, int val)
    {
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *prev = NULL;
        Node *curr = NULL;
        curr = head;
        int i = 0;
        for (i = 1; i < pos && curr != NULL; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (pos > i)
        {
            push_back(val);
        }
        prev->next = newNode;
        newNode->next = curr;
    }
    void pop_front() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << " NULL";
    }
    void sort(int n)
    {
        Node*temp = head;
        while (temp!=NULL)
        {
            Node*min = temp;
            Node*temp1 = temp->next;
            while (temp1 != NULL)
            {
                if(temp1->data<min->data)
                {
                    min = temp1;
                }
                temp1 = temp1->next;
            }
            if(min!= temp)
            {
            double sort = temp->data;
            temp->data = min->data;
            min->data = sort;
            }   
            temp = temp->next;
        }
        
    }
};
int main()
{
   List Salaries;
    int n;
    double salary;
    cout<<"Enter Number of Employees: ";
    cin>>n;
    cout<<"Enter Salary of each Employee "<<endl;
    cout<<"Employee 1 : ";
    cin>>salary;
    Salaries.push_front(salary); 
    for (int i = 1; i < n; i++)
    {
       cout<<"Employee "<<i+1<<" : ";
       cin>>salary;
       Salaries.push_back(salary);
    }
    Salaries.display();
    cout<<endl;
    cout<<"Salaries Sorted in Ascending Order "<<endl;
    Salaries.sort(n);
    Salaries.display();
    return 0;
}
