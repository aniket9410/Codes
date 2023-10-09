#include <iostream>

struct Node {
  int data;
  Node* next;
};

void insertAtBeginning(Node*& head, int newData) {
  // create new node
  Node* newNode = new Node;
  newNode->data = newData;

  // update new node's next pointer to point to the current head
  newNode->next = head;

  // update head to point to the new node
  head = newNode;
}

int main() {
  // create an empty list
  Node* head = nullptr;

  // get input from user
  std::cout << "Enter the number of nodes to insert: ";
  int n;
  std::cin >> n;

  std::cout << "Enter the values of the nodes: ";
  for (int i = 0; i < n; i++) {
    int value;
    std::cin >> value;
    insertAtBeginning(head, value);
  }

  // print the list
  Node* curr = head;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << std::endl;

  return 0;
}

