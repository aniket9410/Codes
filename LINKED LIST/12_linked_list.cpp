// A complete working C++ program to
// demonstrate all the insertion methods 
// on linked List 
#include<iostream>
using namespace std;

// A linked list node
class Node 
{
    public:
        int data;
        Node *next;
};

// Given a reference (pointer to pointer )
// to the head of a list and an int, inserts
// a new node on the front of the list.
void push(Node** head_ref, int new_data){
    
    // 1. allocate node
    Node* new_node = new Node();

    // 2. put in the data 
    new_node -> data = new_data;

    // 3. make next of new node as head
    new_node->next = (*head_ref);

    // 4. move the head to point 
    // to the new node 
    (*head_ref) = new_node;

}

// Given a node prev_node, insert a new 
// node after the given prev_node
void insertAfter(Node* prev_node, int new_data){

    // 1. check if the given prev_node 
    // is null
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    // 2. allocate new node 
    Node* new_node = new Node();

    // 3. put in the data
    new_node -> data = new_data;

    // 4. Make next of new node 
    // as next of prev_node
    new_node -> next = prev_node -> next;

    // 5. move the next of prev_node 
    // as new_node
    prev_node -> next = new_node;
    
}

// Given a reference (pointer to pointer )
// to the head of a list and an int.
// append a new node at the end 
void append(Node** head_ref, int new_data){

    // 1. allocate node 
    Node* new_node = new Node();

    // used in step 5
    Node *last = *head_ref;

    // 2. put in the data
    new_node -> data = new_data;

    // 3. This new node is going to be 
    // the last node. so make next of 
    // it as null
    new_node -> next = NULL;

    // 4. if the Linked List is empty,
    //then make the new node as head
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    // 5. else traverse till the last node
    while (last-> next != NULL)
    {
        last = last -> next;
    }

    // 6. Change the next of the last node
    last -> next = new_node;
    return;
}

// This function prints contents of 
// linked list starting from head
void printList(Node *node){
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node -> next;
    }
    
}

// Driver code
int main()
{
    // start with the empty list 
    Node* head = NULL;

    // Insert 6. so linked list become 6 -> NULL
    append(&head, 6);

    // insert 7 at the beginning .
    // so linked list becomes 7 -> 6 -> NULL
    push(&head, 7);

    // insert 1 at the beginning.
    // so linked list becomes 1 -> 7 -> 6 -> NULL
    push(&head, 1);

    // insert 4 at the end, so
    // linked list becomes 1 -> 7 -> 6 -> 4 -> NULL
    append(&head, 4);

    // insert 8, after 7. so linked list 
    // becomes 1 -> 7 -> 8 -> 6 -> 4 -> NULL
    insertAfter(head -> next, 8);

    cout << "Created Linked List is: ";
    printList(head);

    return 0;
}
