// Recursive C++ program to reverse a linked list 
#include <iostream>
using namespace std;

// Link list node
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList() { head = NULL;}

    Node* reverse(Node* head)
    {
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }

        // reverse the rest list and put 
        // the first element at the end
        Node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        // fix the head pointer
        return rest;
        
    }


    // Function to print linked list
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL)
        {
            cout << temp -> data << " ";
            temp = temp ->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

// Driver code 
int main()
{
    // start with an empty list 
    LinkedList l1;
    l1.push(20);
    l1.push(4);
    l1.push(15);
    l1.push(85);

    cout << "Given linked list \n";
    l1.print();

    l1.head = l1.reverse(l1.head);

    cout << "\nReversed linked list \n";
    l1.print();
    return 0;
    
}