// a complete working c++ program to demonstrate all insertion 
// methods in a doubly linked list
#include <iostream>
using namespace std;

// a linked list node
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

// given a reference (pointer to pointer)
// to the head of a list
// and an int, inserts a new node on the 
// front of the list.
void push(Node** head_ref, int new_data)
{
    // 1. allocate node
    Node* new_node = new Node();

    // 2. put in the data
    new_node->data = new_data;

    // 3. make next of new node as head
    // and previous as NULL.
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    // 4. change prev of head node to new node
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    
    // 5. move the head to point to the new node
    (*head_ref) = new_node;
}

// given a node as prev_node. 
// insert a new node after the given node
void insertAfter(Node* prev_node, int new_data)
{
    // 1. check if the given prev_node is NUll
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    // 2. allocate new node
    Node* new_node = new Node();

    // 3. put in the data
    new_node->data = new_data;

    // 4. make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // 5. make the next of prev_node as the new_node
    prev_node->next = new_node;

    // 6. make prev_node as previous of new_node
    new_node->prev = prev_node;

    // 7. change previous of new_node's next node
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}
// given a reference (pointer to pointer) to the head of a DLL
// and an int, appends a new node at the end 
void append(Node** head_ref, int new_data)
{
    // 1. allocate node
    Node* new_node = new Node();
    
    Node* last = *head_ref; // used in step 5

    // 2. put in the data
    new_node->data = new_data;

    // 3. this new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;

    // 4. if the linked list is empty then make the new node as head
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    // 5. else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // 6. change the next of last node
    last->next = new_node;

    // 7. make last node as previous of new node
    new_node->prev = last;
    
    return;
    
}

// this function prints contents of the
// linked list starting from the given node
void printList(Node* node)
{
    Node* last;
    cout << "\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    
    cout << "\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout << last->data << " ";
        last = last->prev;
    }
    
}

int main()
{
    // start with the empty list 
    Node* head = NULL;

    // insert 6
    append(&head, 6);

    // insert 7 at the head
    push(&head, 7);
    push(&head, 6);
    push(&head, 9);
    push(&head, 78);
    push(&head, 90);        
    insertAfter(head->next->next, 8);

    cout << "creted dll is: ";
    printList(head);

    return 0;
}
