#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void InsertAtHead(Node* &head,int d){

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void Print(Node* &head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl; 
}

void InsertAtPosition(Node* &tail,Node* &head,int position,int d){
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp ->next;
        cnt++;
    }
    

    //inserting at last position
    // if (temp -> next = NULL)
    // {
    //     InsertAtTail(tail,d);
    //     return;
    // }
    
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    
}
int main(){
    Node *node1 = new Node(10);
    Node *tail = node1;
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    Node* head = node1;
    Print(head);
    InsertAtTail(tail,12);
    Print(head); 
    InsertAtTail(tail,82);
    Print(head); 
    InsertAtTail(tail,19);
    Print(head); 
    InsertAtPosition(tail,head,5,22);
    Print(head);
    InsertAtPosition(tail,head,1,42);
    Print(head);
    InsertAtPosition(tail,head,3,27);
    Print(head);
    cout<<tail->data;
    return 0;

}