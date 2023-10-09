// recursive C++ program to search 
// an element in linked list 
#include <iostream>
using namespace std;

// Link list node
class Node{
    public:
        int key;
        Node* next;
};

// given a reference (pointer to pointer) to the head
// of a list and an int, push a new node on the front
// of the list.
void push(Node** head_ref, int new_key)
{
    // allocate node
    Node* new_node = new Node();

    // put in the key
    new_node -> key = new_key;

    // Link the old list of the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// check whether the value x is present in linked list 
bool search(Node* head, int x)
{
    // base case
    if (head == NULL)
    {
        return false;
    }

    // If the key is present in current node, return true
    if (head->key == x)
    {
        return true;
    }
    
    // recur for remaining list 
    return search(head->next, x);
}

// driver code
int main(){
    Node* head = NULL;
    int x = 11;

    // use push() to construct below list 
    // 14 -> 21 -> 11 -> 30 -> 10
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    // function call
    search(head, x) ? cout << "Yes" : cout << "No";
    return 0;
}
