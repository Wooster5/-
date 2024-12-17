#include <iostream>
#include "C:\!Kostya\Ћабы по инфе\лабы c++\StaticLib\array_utils.h"

int main() {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    setlocale(LC_ALL, "rus");


    sortArray(arr);
    std::cout << "ќтсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    int value = 8;
    int index = findElement(arr, value);
    if (index != -1) {
        std::cout << "Ёлемент " << value << " найден на индексе " << index << "." << std::endl; //hjgkgk
    }
    else {
        std::cout << "Ёлемент " << value << " не найден." << std::endl;
    }


    double avg = calculateAverage(arr);
    std::cout << "—реднее значение: " << avg << std::endl;

    return 0;
}
