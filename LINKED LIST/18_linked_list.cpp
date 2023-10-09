// Tail Recursive C++ program to find length
// or count of nodes in a linked list 
// auxiliary space of a tail recursive function 
// will become O(1)
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

// A tail recursive function to count the nodes of a linked list
// default value of the count is used as zero 
int getCount(Node* head, int count = 0){
    // Base case 
    if (head == NULL)
    {
        return count;
    }

    // move the pointer to next node and increase the count 
    else{
        return getCount(head->next, count + 1);
    }
    
}

// driver code
int main(){
    Node* head = NULL;

    // use push() to construct below list 
    // 14 -> 21 -> 11 -> 30 -> 10
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    push(&head, 98);

    // function call
    cout << "count of nodes is " << getCount(head);
    return 0;
}
