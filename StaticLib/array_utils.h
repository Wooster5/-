#pragma once
#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <vector>
#include <windows.h>
#include <clocale>


void sortArray(std::vector<int>& arr);


int findElement(const std::vector<int>& arr, int value);


double calculateAverage(const std::vector<int>& arr);

#endif // ARRAY_UTILS_H
