#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Задание 1: Реализация стека
// Цепное представление
struct TStack {
    Node* Top;
};

// Сплошное представление (статический массив)
struct TStackArray {
    int data[100];  
    int top = -1;   
};

// Задание 2: Реализация списка
// Цепное представление
struct TList {
    Node* Head;
};

// Сплошное представление
struct TListArray {
    int data[100];  
    int size = 0;   
};

void Push(TStack& s, int value);
int Pop(TStack& s);
void DemoChainStack();
void PushArray(TStackArray& s, int value);
int PopArray(TStackArray& s);
void DemoArrayStack();
void AddToList(TList& l, int value);
void SwapMinFirst(TList& l);
void DemoChainList();
void AddToListArray(TListArray& l, int value);
void SwapMinFirstArray(TListArray& l);
void DemoArrayList();

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    cout << "----- Задание 1: Реализация стека -----\n";
    cout << "\nЦепное представление:\n";
    DemoChainStack();

    cout << "\nСплошное представление:\n";
    DemoArrayStack();

    cout << "\n----- Задание 2: Работа со списком -----\n";
    cout << "\nЦепное представление:\n";
    DemoChainList();

    cout << "\nСплошное представление:\n";
    DemoArrayList();

    return 0;
}

// Реализации функций для стека (цепное)
void Push(TStack& s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s.Top;
    s.Top = newNode;
}

int Pop(TStack& s) {
    if (!s.Top) return INT_MIN;
    Node* temp = s.Top;
    int value = temp->data;
    s.Top = s.Top->next;
    delete temp;
    return value;
}

void DemoChainStack() {
    TStack s = { NULL };
    cout << "Исходный массив: ";
    for (int i = 0; i < 10; i++) {
        int rand_number = rand() % 100;
        cout << rand_number << " ";
        Push(s, rand_number);
    }

    cout << "\nИзвлечено 5 элементов: ";
    for (int i = 0; i < 5; i++) {
        cout << Pop(s) << " ";
    }
    cout << "\nНовая вершина стека: ";
    cout << (s.Top ? to_string(s.Top->data) : "NIL") << endl;
}

// Реализации функций для стека (сплошное)
void PushArray(TStackArray& s, int value) {
    if (s.top < 99) {
        s.data[++s.top] = value;
    }
}

int PopArray(TStackArray& s) {
    if (s.top >= 0) {
        int value = s.data[s.top];
        s.top--;
        return value;
    }
    else {
        return INT_MIN;
    }
}

void DemoArrayStack() {
    TStackArray s;
    cout << "Исходный массив: ";
    for (int i = 0; i < 10; i++) {
        int rand_number = rand() % 100;
        cout << rand_number << " ";
        PushArray(s, rand_number);
    }

    cout << "\nИзвлечено 5 элементов: ";
    for (int i = 0; i < 5; i++) {
        cout << PopArray(s) << " ";
    }
    cout << "\nНовая вершина стека: ";
    if (s.top >= 0) {
        cout << to_string(s.data[s.top]) << endl;
    }
    else {
        cout << "NIL" << endl;
    }
}

// Реализации функций для списка (цепное)
void AddToList(TList& l, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = l.Head;
    l.Head = newNode;
}

void SwapMinFirst(TList& l) {
    if (!l.Head) return;
    Node* minNode = l.Head;
    for (Node* curr = l.Head->next; curr; curr = curr->next) {
        if (curr->data < minNode->data) minNode = curr;
    }
    swap(l.Head->data, minNode->data);
}

void DemoChainList() {
    TList l = { NULL };
    for (int i = 0; i < 10; i++) {
        AddToList(l, rand() % 100);
    }

    cout << "Исходный список: ";
    for (Node* curr = l.Head; curr; curr = curr->next) {
        cout << curr->data << " ";
    }

    SwapMinFirst(l);
    cout << "\nПосле замены: ";
    for (Node* curr = l.Head; curr; curr = curr->next) {
        cout << curr->data << " ";
    }
    cout << endl;
}

// Реализации функций для списка (сплошное)
void AddToListArray(TListArray& l, int value) {
    if (l.size < 100) {
        l.data[l.size++] = value;
    }
}

void SwapMinFirstArray(TListArray& l) {
    if (l.size == 0) return;
    int minIndex = 0;
    for (int i = 1; i < l.size; i++) {
        if (l.data[i] < l.data[minIndex]) minIndex = i;
    }
    swap(l.data[0], l.data[minIndex]);
}

void DemoArrayList() {
    TListArray l;
    for (int i = 0; i < 10; i++) {
        AddToListArray(l, rand() % 100);
    }

    cout << "Исходный список: ";
    for (int i = 0; i < l.size; i++) {
        cout << l.data[i] << " ";
    }

    SwapMinFirstArray(l);
    cout << "\nПосле замены: ";
    for (int i = 0; i < l.size; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}