#include "lab7_17.1_head.h"




void createStack(Node*& P1) {
    srand(time(nullptr)); 

 
    int size = rand() % 10 + 1; 
   
    for (int i = 0; i < size; ++i) {
        int value = rand() % 100 + 1; 
        Node* newNode = new Node{ value, P1 };
        P1 = newNode;
    }
}

void splitStack(Node* P1, Node*& evenStack, Node*& oddStack) {
    Node* current = P1;

    while (current != nullptr) {
        Node* nextNode = current->next;

        if (current->data % 2 == 0) {
            current->next = evenStack;
            evenStack = current;
        }
        else {
            current->next = oddStack;
            oddStack = current;
        }

        current = nextNode;
    }
}
void printStack(const Node* stack) {
    const Node* current = stack;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}


void printStackAddress(const Node* stack) {
    if (stack == nullptr) {
        cout << "NIL";
    }
    else {
        cout << stack;
    }
}