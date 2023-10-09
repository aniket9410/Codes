// Iterative C++ program to reverse a linked list 
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
    LinkedList(){head = NULL;}

    // Function to reverse the linked list 
    void reverse()
    {

        // Initialise current, previous and next pointers
        Node* current = head;
        Node* prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // store next 
            next = current->next;
            
            // Reverse current node's pointer 
            current->next = prev;

            // Move pointers one position ahead 
            prev = current;
            current = next;
        }
        head = prev;  
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

    l1.reverse();

    cout << "\nReversed linked list \n";
    l1.print();
    return 0;
    
}