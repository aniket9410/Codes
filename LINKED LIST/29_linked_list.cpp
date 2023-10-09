// insertion and deletion in a circular singly linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// function to insert a node at the 
// beginning of a circular linked list 
void push(Node** head_ref, int data)
{
    // create a new node and make head
    // as next of it 
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;


    // if linked list is not NuLL then 
    // set the next of last node
    if (*head_ref != NULL)
    {
        // find the node before head and 
        // update next of it 
        Node * temp = *head_ref;
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = ptr1;
    }
    else{
        // for the first node
        ptr1->next = ptr1;
    }
    *head_ref = ptr1;
}

// function to print nodes on a given 
// circular linked list 
void printlist(struct Node* head)
{
    Node* temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    cout << endl;
}

// function to delete a given node in 
// a circular linked list
void deleteNode(Node** head, int key)
{
    // if linked list is empty
    if (*head == NULL)
    {
        return;
    }
    // if the list contains only a 
    // single node
    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *last = *head, *d;

    // if head is to be deleted 
    if ((*head)->data == key){
        // find the last node of the list 
        while (last->next != *head)
        {
            last = last->next;
        }
        // point last node to the next of 
        // head i.e the second node 
        // of the list
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
        return;
    }

    // either the node to be deleted is not found 
    // of the end if list is not reached
    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }
    
    // if node to be deleted was found
    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else{
        cout << "given node is not found in the list" << endl;
    }
}

int main()
{
    Node* head = NULL;

    push(&head, 5);
    push(&head, 9);
    push(&head, 4);
    push(&head, 6);
    push(&head, 7);

    cout << "list before deletion: ";
    printlist(head);

    deleteNode(&head, 7);

    cout << "list after deletion: ";
    printlist(head);
}