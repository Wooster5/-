#include "array_processor.h"
#include <algorithm>
#include <numeric>
#include <vector>

// Класс ArrayProcessor
class ArrayProcessor {
private:
    std::vector<int> arr;

public:
    ArrayProcessor(const std::vector<int>& inputArr) : arr(inputArr) {}

    std::vector<int> sortArray() {
        std::sort(arr.begin(), arr.end());
        return arr;
    }

    int findElement(int value) const {
        auto it = std::find(arr.begin(), arr.end(), value);
        return (it != arr.end()) ? std::distance(arr.begin(), it) : -1;
    }

    double calculateAverage() const {
        if (arr.empty()) return 0.0;
        return static_cast<double>(std::accumulate(arr.begin(), arr.end(), 0)) / arr.size();
    }
};

// Обёртки для функций библиотеки
extern "C" {
    void* __stdcall createArrayProcessor(const int* arr, int size) {
        return new ArrayProcessor(std::vector<int>(arr, arr + size));
    }

    void __stdcall destroyArrayProcessor(void* instance) {
        delete static_cast<ArrayProcessor*>(instance);
    }

    void __stdcall sortArray(void* instance, int* sortedArr, int size) {
        auto processor = static_cast<ArrayProcessor*>(instance);
        std::vector<int> sorted = processor->sortArray();
        std::copy(sorted.begin(), sorted.end(), sortedArr);
    }

    int __stdcall findElement(void* instance, int value) {
        auto processor = static_cast<ArrayProcessor*>(instance);
        return processor->findElement(value);
    }

    double __stdcall calculateAverage(void* instance) {
        auto processor = static_cast<ArrayProcessor*>(instance);
        return processor->calculateAverage();
    }
}
