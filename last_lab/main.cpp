#include <iostream>
#include "C:\!Kostya\Ћабы по инфе\лабы c++\StaticLib\array_utils.h"

int main() {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    setlocale(LC_ALL, "rus");
 

    int valuex = 9;

    sortArray(arr);
    std::cout << "ќтсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    int value = 8;
    int index = findElement(arr, value);
    if (index != -1) {
        std::cout << "Ёлемент " << value << " найден на индексе " << index << "." << std::endl; //12345
    }
    else {
        std::cout << "Ёлемент " << value << " не найден." << std::endl;
    }


    double avg = calculateAverage(arr);
    std::cout << "—реднее значение: " << avg << std::endl;

    int index1 = binarySearch(arr, valuex);

    if (index1 != -1) {
        std::cout << "Ёлемент " << valuex << " найден на индексе " << index1 << "." << std::endl;
    }
    else {
        std::cout << "Ёлемент " << valuex << " не найден." << std::endl;
    }

    return 0;
}
