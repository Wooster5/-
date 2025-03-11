#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct ArrayPointer {
    int* ptr;       
    int* start;     
    int* end;       
};


ArrayPointer* NewPointer(int size) {
    ArrayPointer* ap = new ArrayPointer;
    ap->start = new int[size];
    ap->ptr = ap->start;
    ap->end = ap->start + size;
    return ap;
}


void SetPointer(ArrayPointer* ap, int pos) {
    if (ap->start + pos < ap->end) {
        ap->ptr = ap->start + pos;
    }
}

void WritePointer(ArrayPointer* ap, int value) {
    *(ap->ptr) = value;
}

int ReadPointer(ArrayPointer* ap) {
    return *(ap->ptr);
}

void FreePointer(ArrayPointer* ap) {
    delete[] ap->start;
    delete ap;
}

int InputNumber(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите целое число.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    do {
        n = InputNumber("Введите размер массива (>0): ");
    } while (n <= 0);

    ArrayPointer* ap = NewPointer(n);

    for (int i = 0; i < n; i++) {
        SetPointer(ap, i);
        int val = InputNumber("Введите элемент #" + to_string(i + 1) + ": ");
        WritePointer(ap, val);
    }

    long long product = 1;
    bool hasPositive = false;

    for (int i = 0; i < n; i++) {
        SetPointer(ap, i);
        int value = ReadPointer(ap);

        if (value > 0) {
            product *= value;
            hasPositive = true;
        }
    }

    if (hasPositive) {
        cout << "Произведение положительных элементов: " << product << endl;
    }
    else {
        cout << "Нет положительных элементов для умножения" << endl;
    }

    FreePointer(ap);
    return 0;
}