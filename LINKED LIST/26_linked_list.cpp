// c++ program to find nth node
// in the linked list using recursion

#include <iostream>
using namespace std;

// Linked list node
struct Node{
    int data;
    struct Node* next;

};

// given a reference (pointer to pointer) to 
// the head of a list and an int, push a new 
// on the front of the list.
void push(struct Node** head_ref, int new_data)
{
    // allocate node 
    Node* new_node = new Node();
    
    // put in the data 
    new_node->data = new_data;

    // link the old list of the new node 
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// takes head pointer of the linked list and index as arguments and return
// data at index. (don't use another variable)
int Getnth(struct Node* head, int n)
{
    // if length of the list is less 
    // then the given index, return -1
    if (head == NULL)
    {
        return -1;
    }

    // if n equal to 0 return node->data
    if(n== 0)
    {
        return head->data;
    }

    // increase head to next pointer 
    // n-1 decrease the number of recursion until n = 0
    return Getnth(head->next, n-1);
    
}

int main()
{
    struct Node* head = NULL;
    
    push(&head, 1);
    push(&head, 6);
    push(&head, 9);
    push(&head, 12);
    push(&head, 98);

    cout << Getnth(head, 3);
}