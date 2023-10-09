// an alternate method using constructor call
// to insert elements in a linked list

#include <iostream>
using namespace std;

class node{
public:
    node* prev;
    int data;
    node* next;

    node(int value)
    {
        // A constructor is called here 
        prev = NULL; // by default previous pointer is pointed to null
        data = value;
        next = NULL; // by default next pointer is pointed to null
    }
};

void insert_at_head(node*&head, int value)
{
    node* n = new node(value);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insert_at_tail(node*&head, int value)
{
    if (head == NULL)
    {
        insert_at_head(head, value);
        return;
    }
    node* n = new node(value);
    node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node* head= NULL; // declaring an empty doubly linked list

    insert_at_tail(head, 1);
    insert_at_tail(head, 9);
    insert_at_tail(head, 5);
    insert_at_tail(head, 7);
    insert_at_tail(head, 12);
    insert_at_tail(head, 4);

    cout << "After insertion at tail: ";
    display(head);

    cout << "After insertion at head: ";
    insert_at_head(head, 0);
    insert_at_head(head, 76);
    display(head);
}