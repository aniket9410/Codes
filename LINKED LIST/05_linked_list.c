//Print reverse linked list using recursion
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void Print(struct Node* p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d ",p -> data);
    Print(p -> next);

}
void ReversePrint(struct Node* p){
    if (p == NULL)
    {
        return;
    }
    ReversePrint(p -> next);
    printf("%d ",p -> data);
}
struct Node* Insert(struct Node* head,int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if (head == NULL) head = temp;
    else{
        struct Node* temp1 = head;
        while (temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
    }
    return head;
    
}
int main()
{
    struct Node* head = NULL;
    head = Insert (head, 9);
    head = Insert (head, 4);
    head = Insert (head, 5);
    head = Insert (head, 7);
    head = Insert (head, 6);
    Print(head);
    printf("\nReversed List\n");
    ReversePrint(head);
}