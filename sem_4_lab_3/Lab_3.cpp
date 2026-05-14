#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;

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

template<typename T>
void freePtr(T*& ptr) {
    if (ptr) {
        delete ptr;
        ptr = nullptr;
    }
}

template<typename T>
void freePtr(T*& arr, bool isArray) {
    if (arr) {
        delete[] arr;
        arr = nullptr;
    }
}

template<typename T>
void freePtr(T**& ptrArr, int size) {
    if (ptrArr) {
        for (int i = 0; i < size; i++) {
            delete ptrArr[i];
        }
        delete[] ptrArr;
        ptrArr = nullptr;
    }
}

void InputIntElemsArr(int* arr, int size) {
    cout << "\nЗаполните массив:\n\n";
    for (int i = 0; i < size; i++) {
        arr[i] = InputNumber(to_string(i + 1) + ") ");
    }
}

void NewPointer(int* arr, int size, int**& ptrArr) {
    ptrArr = new int* [size];
    for (int i = 0; i < size; i++) {
        ptrArr[i] = new int(arr[i]);
    }
}

void NewPointer(double* arr, int size, double**& ptrArr) {
    ptrArr = new double* [size];
    for (int i = 0; i < size; i++) {
        ptrArr[i] = new double(arr[i]);
    }
}

void SetPointer(double*& p1, unsigned* p2) {
    if (p2 == nullptr) {
        cerr << "Ошибка: указатель p2 пустой!\n";
        return;
    }

    if (p1 == nullptr) {
        p1 = new double;
    }

    *p1 = static_cast<double>(*p2);
}

void GenerateRandomElemsArr(double* arr, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 20001 - 10000) / 100.0;
        cout << i + 1 << " элемент массива = " << arr[i] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    double* p1 = nullptr;
    unsigned* p2 = new unsigned(42);

    int choice;
    do {
        choice = InputNumber("\nВведите номер задания (1 или 2): ");
    } while (choice != 1 && choice != 2);

    int size;
    while (true) {
        size = InputNumber("Введите размер массива: ");

        if (size <= 0) {
            cout << "Размер массива должен быть больше нуля!\n";
        }
        else if (size > 32) {
            cout << "Память закончилась\n";
        }
        else {
            break;
        }
    }

    switch (choice) {
    case 1: {
        int* arr = new int[size];
        InputIntElemsArr(arr, size);

        int** ptrArr;
        NewPointer(arr, size, ptrArr);

        int product = 1;
        bool hasPositive = false;
        for (int i = 0; i < size; i++) {
            if (*ptrArr[i] > 0) {
                product *= *ptrArr[i];
                hasPositive = true;
            }
        }

        if (hasPositive) {
            cout << "\nПроизведение положительных элементов: " << product << endl;
        }
        else {
            cout << "\nНет положительных элементов\n";
        }

        freePtr(arr, true);
        freePtr(ptrArr, size);
        break;
    }

    case 2: {
        double* arr = new double[size];
        GenerateRandomElemsArr(arr, size);

        double** ptrArr;
        NewPointer(arr, size, ptrArr);

        double sumNeg = 0.0;
        for (int i = 0; i < size; i++) {
            if (*ptrArr[i] < 0) {
                sumNeg += *ptrArr[i];
            }
        }

        printf("\nСумма отрицательных элементов = %.2f\n", sumNeg);

        freePtr(arr, true);
        freePtr(ptrArr, size);
        break;
    }
    }

    freePtr(p1);
    freePtr(p2);
    return 0;
}