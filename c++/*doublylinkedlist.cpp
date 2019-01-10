// Author : FangY
// Date   :

#include<iostream>
using namespace std;
struct Node{
    Node *prev;
    int data;
    Node *next;
};
class doublyLinkList{
public:
    doublyLinkList();
    void creatList1(int num);//append the number in the end of the list
    void creatList2(int num);//append the number in the head of the list
    int lengthList();
    void Display();
    ~doublyLinkList();
private:
    Node *head;
    Node *tail;
    int length;
};
doublyLinkList::doublyLinkList(){
    head=NULL;
    tail=NULL;
    length=0;
}
doublyLinkList::~doublyLinkList(){
    Node *temp=head;
    while(head!=tail){
        head=head->next;
        delete temp;
        temp=head;
    }
}
void doublyLinkList::creatList1(int num){
    if(head==NULL){
        head=new Node();
        head->data=num;
        length++;
        tail=head;
    }
    else{
        tail->next=new Node();
        tail->next->data=num;
        length++;
        tail->next->prev=tail;
        tail=tail->next;
    }
}
void doublyLinkList::creatList2(int num){
    if(head==NULL){
        head=new Node();
        head->data=num;
        length++;
        tail=head;
    }
    else{
        head->prev=new Node();
        head->prev->data=num;
        length++;
        head->prev->next=head;
        head=head->prev;
    }
}
int doublyLinkList::lengthList(){
    return length;
}
void doublyLinkList::Display(){
    Node *temp;
    temp=head;
    while(temp->next){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<temp->data;
}
int main()
{
    int a;
    doublyLinkList linklist;
    linklist.creatList1(3);
    linklist.creatList1(5);
    linklist.creatList2(7);
    a=linklist.lengthList();
    cout<<a<<endl;
    linklist.Display();
}

