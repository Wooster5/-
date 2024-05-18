#include "lab7_17.1_head.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Node* P1 = nullptr;

    createStack(P1);

    cout << "Исходный стек: ";
    printStack(P1);
    cout << std::endl;

    Node* evenStack = nullptr;
    Node* oddStack = nullptr;
    splitStack(P1, evenStack, oddStack);

    cout << "Стек с четными элементами: ";
    printStack(evenStack);
    cout << std::endl;

    cout << "Стек с нечетными элементами: ";
    printStack(oddStack);
    cout << std::endl;

    cout << "Адрес вершины стека с четными элементами: ";
    printStackAddress(evenStack);
    cout << endl;

    cout << "Адрес вершины стека с нечетными элементами: ";
    printStackAddress(oddStack);
    cout << endl;

    return 0;
}