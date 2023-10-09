// A complete working c++ program to
// demonstrate deletion in singly
// linked list with class
#include <iostream>
using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node *next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the list
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// given a reference (pointer to pointer)
// to the head of a list and a key, deletes 
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{
    // store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // If the node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        // changed head 
        *head_ref = temp->next;

        // free old head
        delete temp;
        return;
    }

    // else search for the key to be deleted
    // keep track of the previous code as
    // we need to change "prev->next"
    else{
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        
        // if key was not present in linked list
        if (temp == NULL)
        {
            return;
        }
        // Unlock the node from linked list 
        prev->next = temp->next;

        // free memory
        delete temp;
    }
}

void printList(Node* head){
    while (head)
    {
        if (head->next == NULL)
        {
            cout << " [" << head->data << "] " 
            << " [" << head << "]->" << "(nil)" << endl;
        }
        else{
            cout << " [" << head->data << "] "
            << "[" << head << "]->" << head->next << endl;
        }
        head = head->next;
    }
    cout<< endl <<endl;

}

int main()
{
    // start with the empty list
    Node* head = NULL;

    // Add elements in linked list
    push(&head, 7);
    push(&head, 90);
    push(&head, 98);
    push(&head, 3);
    push(&head, 4);
    push(&head, 12);

    cout << "created linked list: " << endl;
    printList(head);

    deleteNode(&head, 3);
    cout << "\nLinked list after deletion: " << endl;
    printList(head);
}