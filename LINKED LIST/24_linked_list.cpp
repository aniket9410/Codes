// c++ program to delete a node in
// singly linked list recursively
#include <iostream>
using namespace std;

struct node {
    int info;
    node* link = NULL;
    node() {}
    node(int a)
        : info(a)
    {

    }
};

// deletes the node containing 'info'
// part as val and alter the head of
// the linked list (recursive method)
void deleteNode(node*& head, int val)
{

    // check if the list is empty or we 
    // reach at the end of the list
    if (head == NULL)
    {
        cout << "element not present in the list\n";
        return;
    }

    // if current node is the 
    // node to be deleted
    if (head->info == val)
    {
        node* t = head;

        // if it's start of the node head
        // node points to second node's link
        head = head->link;

        // else changes previous node's
        // link to the current node's link
        delete(t);
        return;
    }
    deleteNode(head->link, val);
    
}

// utility function to add a 
// node in the linked list 
// here we are passing head by
// reference thus no need to return it to the main function
void push(node*&head, int data)
{
    node* newNode = new node(data);
    newNode->link = head;
    head = newNode;
}

// Utility function to print 
// the linked list (recursive method)
void print(node* head)
{
    // cout << endl gets implicitly 
    // typecasted to bool value 
    // 'true'
    if (head == NULL && cout << endl)
    {
        return;
    }
    cout << head->info << " ";
    print(head->link);
}

int main()
{
    // starting with an empty linked list 
    node* head = NULL;

    // adds new element at the beginning of the list 
    push(head, 10);
    push(head, 90);
    push(head, 70);
    push(head, 18);
    push(head, 87);
    push(head, 54);

    // original list
    print(head);

    // call to delete function
    deleteNode(head, 18);

    print(head);
}