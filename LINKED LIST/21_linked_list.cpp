// c++ program to reverse a linked list using stack
#include<iostream>
#include <stack>
using namespace std;

// Create a class Node to enter values and address in the list
class Node {
    public:
        int data ;
        Node* next;
};

// function to reverse the linked list 
void reverseLL(Node** head)
{
    // Create a stack 's' of Node type
    stack<Node*> s;
    Node* temp = *head;
    while (temp->next != NULL)
    {
        // Push all the nodes in to stack
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while (!s.empty())
    {
        // store the top value of stack in list
        temp->next = s.top();
        // pop the value from stack
        s.pop();
        // update the next pointer in the list
        temp = temp->next;
    }
    temp->next = NULL;
}

// Function to display the elements in List 
void printlist(Node* temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp -> next;
    }
}

// Program to insert back of the linked list 
void insert_back(Node** head, int value)
{
    // we have used insertion at back method to enter values
    // in the list.(eg: head->1->2->3->4->Null)
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;

    // if *head equals to null
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    else{
        Node* last_node = *head;
        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = temp;
        return;
    }
}

// Driver code
int main()
{
    Node* head = NULL;
    insert_back(&head, 1);
    insert_back(&head, 4);
    insert_back(&head, 7);
    insert_back(&head, 12);
    insert_back(&head, 195);
    cout << "Given linked list\n";
    printlist(head);
    reverseLL(&head);
    cout << "\nReversed linked list\n";
    printlist(head);
    return 0;
}