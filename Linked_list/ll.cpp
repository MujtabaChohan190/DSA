#include<iostream>
#include<string>
using namespace std;
class node
{
    public:
    node* next;
    int data;
    node():data(0),next(NULL){}
    node(int val):data(val),next(NULL){}

};
class linkedlist
{
    public:
    node* head;
    linkedlist():head(NULL){}
    void insert_at_end(int val)
    {
        if(head==NULL)
        {
            head=new node(val);
            return;
        }
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new node(val);
    }
    void printlist()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void insert_at_head(int val)
    {
        node*temp=new node(val);
        temp->next=head;
        head=temp;
    }
    void search(int target)
    {
        if(head==nullptr)
        {
            cout<<"Value not found!"<<endl;
            return;
        }
        node* temp=head;
        int count=0;
        while(temp->data!=target && temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(temp->data!=target)
        {
            cout<<"Value not found!"<<endl;
            return;
        }
        cout<<"value at "<<count+1<<" node"<<endl;
    }
    int sizeoflist()
    {
        node*temp=head;
        if(head==NULL)
        {
            return 0;
        }
        int count=1;
        while(temp->next!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    void deletion_at_tail()
    {
        node*temp=head;
        if(temp==NULL || temp->next==NULL)
        {
            delete head;
            head=nullptr;
            return;
        }
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    void deletion_before_specific(int target)
    {
        node* temp=head;
        node*p;//previous
        if(head==nullptr || head->data==target)
        {
            return;
        }
        if(head->next->data==target)
        {
            node* todel=head;
            head=head->next;
            delete todel;
            return;
        }
        while(temp->next!=nullptr && temp->next->data!=target)
        {
            p=temp;
            temp=temp->next;
        }
        if(temp->next==nullptr)
        {
            return;
        }
        p->next=temp->next;
        delete temp;
    }
    void deletion_at_specific(int target)
    {
        if(!head)
        {
            return;
        }
        else if(head->data==target)
        {
            node* todel=head;
            head=head->next;
            delete todel;
            todel=nullptr;
            return;
        }
        node* temp=head;
        while(temp->next!=nullptr && temp->next->data!=target)
        {
            temp=temp->next;
        }
        if(temp->next)
        {
            node* todel=temp->next;
            temp->next=temp->next->next;
            delete todel;
            todel=nullptr;
        }
    }
    void deletion_after_specific(int target)
    {
        if(head==nullptr||(head->next==nullptr && head->data==target))
        return;
        node* temp=head;
        node* after=head->next;
        while(temp!=nullptr && temp->data!=target)
        {
            temp=temp->next;
            if(temp->next==nullptr)
            {
                return;
            }
            after=temp->next;
        }
        if(temp==nullptr)
        {
            return;
        }
        node*todel=after;
        temp->next=after->next;
        delete todel;
    }
    void insert_after_specific(int target,int val)
    {
        if(head==nullptr ||(head->next==nullptr && head->data==target ))
        {
            return;
        }
        node* temp=head;
        node* after=temp->next;
        while(temp!=nullptr && temp->data!=target)
        {
            temp=temp->next;
            if(temp->next==nullptr)
            {
                return;
            }
            after=temp->next;
        }
        if(temp==nullptr)
        return;
        node*newnode=new node(val);
        temp->next=newnode;
        newnode->next=after;
    }
    void insert_before_specific(int target,int val)
    {
        if(head==nullptr)
        {
            return;
        }
        node*newnode=new node(val);
        if(head->data==target)
        {
            newnode->next=head;
            head=newnode;
            return;
        }
        node*temp=head;
        node*prev=head;
        while(temp!=nullptr && temp->data!=target)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==nullptr)
        {
            return;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
    node*find_middle()
    {
        int mid=sizeoflist()/2;
        int count=0;
        node*temp=head;
        while(temp!=nullptr && count!=mid)
        {
            count++;
            temp=temp->next;
        }
        return temp;
    }
};
int main()
{
    linkedlist l;
    l.insert_at_end(1);
    l.insert_at_end(2);
    l.insert_at_end(3);
    l.insert_at_end(4);
    l.insert_at_end(5);
    l.insert_after_specific(1,3);
    l.insert_before_specific(1,6);
    l.deletion_at_tail();
    l.deletion_at_specific(2);
    l.deletion_after_specific(1);
    l.printlist();
    l.search(5);
    if(l.head!=nullptr)
    {
        cout<<l.head->data<<endl;
    }
    cout<<l.sizeoflist()<<endl;
    linkedlist l2;
    l2.head=l.find_middle();
    l2.printlist();
}
