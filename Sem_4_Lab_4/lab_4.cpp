#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <clocale>

using namespace std;

struct SortStats {
    long long comparisons = 0;
    long long swaps = 0;
    long long iterations = 0;
    double time = 0.0;
};

enum ArrayType {
    RANDOM,
    SORTED,
    REVERSED,
    PARTIAL_25,
    PARTIAL_50,
    PARTIAL_75
};

SortStats insertionSort(int arr[], int n) {
    SortStats stats;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        stats.iterations++;

        bool comparisonsDone = false;
        while (j >= 0) {
            stats.comparisons++;
            comparisonsDone = true;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                stats.swaps++;
                stats.iterations++;
            }
            else {
                break;
            }
        }
        if (!comparisonsDone) {
            stats.comparisons++;
        }

        arr[j + 1] = key;
    }

    auto end = chrono::high_resolution_clock::now();
    stats.time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return stats;
}

SortStats selectionSort(int arr[], int n) {
    SortStats stats;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        stats.iterations++;
        for (int j = i + 1; j < n; j++) {
            stats.comparisons++;
            stats.iterations++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            stats.swaps++;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    stats.time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return stats;
}

SortStats bubbleSort(int arr[], int n) {
    SortStats stats;
    auto start = chrono::high_resolution_clock::now();

    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        stats.iterations++;
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            stats.iterations++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                stats.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    auto end = chrono::high_resolution_clock::now();
    stats.time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return stats;
}

int partition(int arr[], int low, int high, SortStats& stats) {
    // Выбор медианы трёх
    int mid = low + (high - low) / 2;
    int pivotVal = max(min(arr[low], arr[mid]), min(max(arr[low], arr[mid]), arr[high]));
    int pivotIndex = (arr[low] == pivotVal) ? low : (arr[mid] == pivotVal) ? mid : high;

    swap(arr[pivotIndex], arr[high]); // Переносим опорный элемент в конец
    int pivot = arr[high];

    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        stats.comparisons++;
        stats.iterations++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            stats.swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    stats.swaps++;
    return i + 1;
}


void quickSort(int arr[], int low, int high, SortStats& stats) {

    if (low < high) {
        int pi = partition(arr, low, high, stats);
        quickSort(arr, low, pi - 1, stats);
        quickSort(arr, pi + 1, high, stats);
    }
}

SortStats quickSortWrapper(int arr[], int n) {
    SortStats stats;
    auto start = chrono::high_resolution_clock::now();

    quickSort(arr, 0, n - 1, stats);

    auto end = chrono::high_resolution_clock::now();
    stats.time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return stats;
}

void generateArray(int arr[], int n, ArrayType type) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    switch (type) {
    case SORTED:
        sort(arr, arr + n);
        break;
    case REVERSED:
        sort(arr, arr + n);
        reverse(arr, arr + n);
        break;
    case PARTIAL_25: {
        int part = n * 0.25;
        sort(arr, arr + part);
        break;
    }
    case PARTIAL_50: {
        int part = n * 0.5;
        sort(arr, arr + part);
        break;
    }
    case PARTIAL_75: {
        int part = n * 0.75;
        sort(arr, arr + part);
        break;
    }
    default:
        break;
    }
}

void printStatsTable(const string& methodName, const SortStats& stats) {
    cout << left << setw(20) << methodName
        << setw(15) << stats.comparisons
        << setw(10) << stats.swaps
        << setw(15) << fixed << setprecision(2) << stats.time
        << setw(15) << stats.iterations << endl;
}

void runSingleTest(int size, ArrayType type) {
    int* originalArr = nullptr;
    int* arrInsertion = nullptr;
    int* arrSelection = nullptr;
    int* arrBubble = nullptr;
    int* arrQuick = nullptr;

    try {
        originalArr = new int[size];
        arrInsertion = new int[size];
        arrSelection = new int[size];
        arrBubble = new int[size];
        arrQuick = new int[size];

        generateArray(originalArr, size, type);

        copy(originalArr, originalArr + size, arrInsertion);
        copy(originalArr, originalArr + size, arrSelection);
        copy(originalArr, originalArr + size, arrBubble);
        copy(originalArr, originalArr + size, arrQuick);

        cout << "\nТип массива: ";
        switch (type) {
        case RANDOM: cout << "Случайный"; break;
        case SORTED: cout << "Отсортированный"; break;
        case REVERSED: cout << "Обратный порядок"; break;
        case PARTIAL_25: cout << "Частично отсортированный (25%)"; break;
        case PARTIAL_50: cout << "Частично отсортированный (50%)"; break;
        case PARTIAL_75: cout << "Частично отсортированный (75%)"; break;
        }
        cout << " (Размер: " << size << ")\n";

        cout << "---------------------------------------------------------------" << endl;
        cout << left << setw(20) << "Метод"
            << setw(15) << "Сравнения"
            << setw(10) << "Обмены"
            << setw(15) << "Время (мс)"
            << setw(15) << "Итерации" << endl;

        SortStats insertionStats = insertionSort(arrInsertion, size);
        printStatsTable("Сортировка вставками", insertionStats);

        SortStats selectionStats = selectionSort(arrSelection, size);
        printStatsTable("Сортировка выбором", selectionStats);

        SortStats bubbleStats = bubbleSort(arrBubble, size);
        printStatsTable("Пузырьковая", bubbleStats);

        SortStats quickStats = quickSortWrapper(arrQuick, size);
        printStatsTable("Быстрая сортировка", quickStats);

        cout << "---------------------------------------------------------------" << endl;

    }
    catch (const bad_alloc& e) {
        cerr << "Ошибка выделения памяти для размера " << size << ": " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка при сортировке для размера " << size << ": " << e.what() << endl;
    }

    delete[] originalArr;
    delete[] arrInsertion;
    delete[] arrSelection;
    delete[] arrBubble;
    delete[] arrQuick;
}

void runTests() {
    vector<int> sizes = { 20, 500, 1000, 5000, 10000 };
    vector<ArrayType> arrayTypes = { RANDOM, SORTED, REVERSED, PARTIAL_25, PARTIAL_50, PARTIAL_75 };

    cout << "\n=== Запуск тестов производительности ===" << endl;
    for (int size : sizes) {
        for (ArrayType type : arrayTypes) {
            runSingleTest(size, type);
        }
    }
}

int partitionDescendingAbs(int arr[], int low, int high, SortStats& stats) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        stats.comparisons++;
        if (abs(arr[j]) >= abs(pivot)) {
            i++;
            swap(arr[i], arr[j]);
            stats.swaps++;
        }
        stats.iterations++;
    }
    swap(arr[i + 1], arr[high]);
    stats.swaps++;
    return i + 1;
}

void quickSortDescendingAbs(int arr[], int low, int high, SortStats& stats) {
    if (low < high) {
        int pi = partitionDescendingAbs(arr, low, high, stats);
        quickSortDescendingAbs(arr, low, pi - 1, stats);
        quickSortDescendingAbs(arr, pi + 1, high, stats);
    }
}

void customQuickSortTask() {
    const int size = 15;
    int arr[size];
    SortStats stats;

    for (int i = 0; i < size; ) {
        if (cin >> arr[i]) {
            i++; 
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Пожалуйста, введите целое число: ";
        }
    }

    quickSortDescendingAbs(arr, 0, size - 1, stats);

    cout << "\nРезультат сортировки (по убыванию модулей): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    int choice;
    cout << "1. Запустить тесты производительности\n"
        << "2. Отсортировать 15 элементов\n"
        << "Выберите действие: ";
    cin >> choice;

    if (choice == 1) {
        runTests();
    }
    else if (choice == 2) {
        customQuickSortTask();
    }
    else {
        cout << "Некорректный выбор!" << endl;
    }

    return 0;
}