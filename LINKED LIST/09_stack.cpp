//Stack object oriented implementation using arrays
#include <iostream>
using namespace std;
#define MAX_SIZE 101

class stack
{
private:
    int A[MAX_SIZE]; // array to store the stack
    int top;  // variable to mark the top index of stack
public:
    // constructor
    stack()
    {
        top = -1;  // for empty array
    }

    // Push operation to insert an element on top of the stack
    void Push(int x)
    {
        if (top == MAX_SIZE - 1)  // overflow case
        {
            cout<<"Error : stack overflow"<<endl;
            return;
        }
        A[++top] = x;
    }

    // Pop operation to remove an element from the top of the stack.
    void Pop()
    {
        if (top == -1) // If stack is empty, pop should throw error
        {
            cout<<"Error : No element to pop"<<endl;
            return;
        }
        top--;
    }

    // Top operation to return element at top of stack .
    int Top()
    {
        return A[top];
    }

    // This function will return 1(true) if stack is empty, 0 (false) otherwise
    int IsEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    // This function is to test the implementation of the stack.
    // ONLY FOR TESTING - NOT A VALID OPERATION WITH STACK 
    // This will print all the elements in the stack at any stage.
    void Print()
    {
        int i;
        cout<<"stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    // code to test the implementation.
    // calling Print() after each push or pop to see the state of stack.
    stack S;
    S.Push(2);S.Print();
    S.Push(5);S.Print();
    S.Push(10);S.Print();
    S.Pop();S.Print();
    S.Push(12);S.Print();
}