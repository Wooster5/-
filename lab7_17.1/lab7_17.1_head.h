#pragma once
#ifndef STACK_OPERATIONS_H
#define STACK_OPERATIONS_H
#include <iostream>
#include <cstdlib> // Для функций rand() и srand()
#include <ctime>   // Для функции time()
#include <clocale>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void createStack(Node*& P1);
void splitStack(Node* P1, Node*& evenStack, Node*& oddStack);
void printStack(const Node* stack);
void printStackAddress(const Node* stack);

#endif // STACK_OPERATIONS_H