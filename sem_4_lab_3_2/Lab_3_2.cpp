#include <iostream>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()
#include <limits>   // Для numeric_limits

using namespace std;

struct ArrayPointer {
    double* ptr;    
    double* start;  
    double* end;    
};

ArrayPointer* NewPointer(int size) {
    ArrayPointer* ap = new ArrayPointer;
    ap->start = new double[size];
    ap->ptr = ap->start;
    ap->end = ap->start + size;
    return ap;
}

void SetPointer(ArrayPointer* ap, int pos) {
    if (ap->start + pos < ap->end) {
        ap->ptr = ap->start + pos;
    }
}

void WritePointer(ArrayPointer* ap, double value) {
    *(ap->ptr) = value;
}

double ReadPointer(ArrayPointer* ap) {
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

double RandomDouble(double min, double max) {
    return min + (max - min) * (rand() / static_cast<double>(RAND_MAX));
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(static_cast<unsigned int>(time(0))); 

    int n;
    do {
        n = InputNumber("Введите размер массива (>0): ");
    } while (n <= 0);

    ArrayPointer* ap = NewPointer(n);

    for (int i = 0; i < n; i++) {
        SetPointer(ap, i);
        double val = RandomDouble(-100.0, 100.0); 
        WritePointer(ap, val);
    }

    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        SetPointer(ap, i);
        cout << ReadPointer(ap) << " ";
    }
    cout << endl;

    double sumNegative = 0.0;
    for (int i = 0; i < n; i++) {
        SetPointer(ap, i);
        double value = ReadPointer(ap);
        if (value < 0) {
            sumNegative += value;
        }
    }

    cout << "Сумма отрицательных элементов: " << sumNegative << endl;

    FreePointer(ap);
    return 0;
}