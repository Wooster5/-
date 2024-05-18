#include "lab7_17.2_head.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Node* P1 = nullptr;

    createStack(P1);

    cout << "�������� ����: ";
    printStack(P1);
    cout << std::endl;

    Node* evenStack = nullptr;
    Node* oddStack = nullptr;
    splitStack(P1, evenStack, oddStack);

    cout << "���� � ������� ����������: ";
    printStack(evenStack);
    cout << std::endl;

    cout << "���� � ��������� ����������: ";
    printStack(oddStack);
    cout << std::endl;

    cout << "����� ������� ����� � ������� ����������: ";
    printStackAddress(evenStack);
    cout << endl;

    cout << "����� ������� ����� � ��������� ����������: ";
    printStackAddress(oddStack);
    cout << endl;

    swapEnds(evenStack);
    swapEnds(oddStack);

    cout << "���� � ������� ���������� ����� ������: ";
    printStack(evenStack);
    cout << endl;

    cout << "���� � ��������� ���������� ����� ������: ";
    printStack(oddStack);
    cout << endl;

    return 0;
}