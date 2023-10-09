// c++ program to find nth node 
// in the linked list 

#include <iostream>
#include <assert.h>
using namespace std;

// link list node 
class Node {
    public:
        int data;
        Node* next;
};

// given a reference (pointer to pointer)
// to the head of a list and an int,
// push a new node on the front of the list.
void push(Node** head_ref, int new_data)
{
    // allocate node 
    Node* new_node = new Node();

    // put in the data 
    new_node->data = new_data;

    // link the old list 
    // of the new node 
    new_node->next = (*head_ref);

    // move the head to point 
    // to the new node 
    (*head_ref) = new_node;
}

// takes head pointer of the linked list 
// and index as argument and return
// data at index
int GetNth(Node* head, int index)
{
    Node* current = head;

    // the index of the node
    // we're currently looking at 
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
        {
            return (current->data);
        }
        count++;
        current = current->next;
    }
    
    // if we get to this line 
    // the caller was asking for
    // a non existent element so we assert fail
    assert(0);
}

int main()
{
    // start with the empty list 
    Node* head = NULL;

    push(&head, 1);
    push(&head, 98);
    push(&head, 8);
    push(&head, 56);
    push(&head, 2);
    push(&head, 6);

    // check the count function
    cout << "Element at the index " << GetNth(head, 4);
    return 0;
}