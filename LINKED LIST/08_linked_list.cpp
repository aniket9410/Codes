// Reverse a linked list using iterative method in c++
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* Insert(Node* head,int data)
{
    Node* temp = new Node();
    temp -> data = data;
    temp -> next = NULL;
    if (head == NULL) head = temp;
    else{
        Node* temp1 = head;
        while (temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
    }
    return head;
    
}
void Print(Node* p)
{
    if (p == NULL)
    {
        return;
    }
    cout<< p -> data << " ";
    Print(p -> next);

}
Node* Reverse(struct Node* head)
{
    Node* current, *prev, *next ;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int main()
{
    Node* head = NULL;
    head = Insert (head, 9);
    head = Insert (head, 4);
    head = Insert (head, 5);
    head = Insert (head, 7);
    head = Insert (head, 6);
    Print(head);
    cout<<"\nReversed List\n";
    head = Reverse(head);
    Print(head);
}