#include "array_utils.h"
#include <algorithm>
#include <numeric>

void sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

int findElement(const std::vector<int>& arr, int value) {
    auto it = std::find(arr.begin(), arr.end(), value);
    return (it != arr.end()) ? std::distance(arr.begin(), it) : -1;
}

double calculateAverage(const std::vector<int>& arr) {
    if (arr.empty()) return 0.0;
    return static_cast<double>(std::accumulate(arr.begin(), arr.end(), 0)) / arr.size();
}
