#include <iostream>
#include "C:\!Kostya\���� �� ����\���� c++\StaticLib\array_utils.h"

int main() {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    setlocale(LC_ALL, "rus");
 

    int valuex = 9;

    sortArray(arr);
    std::cout << "��������������� ������: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    int value = 8;
    int index = findElement(arr, value);
    if (index != -1) {
        std::cout << "������� " << value << " ������ �� ������� " << index << "." << std::endl; //12367
    }
    else {
        std::cout << "������� " << value << " �� ������." << std::endl;
    }


    double avg = calculateAverage(arr);
    std::cout << "������� ��������: " << avg << std::endl;

    int index1 = binarySearch(arr, valuex);

    if (index1 != -1) {
        std::cout << "������� " << valuex << " ������ �� ������� " << index1 << "." << std::endl;
    }
    else {
        std::cout << "������� " << valuex << " �� ������." << std::endl;
    }

    return 0;
}
