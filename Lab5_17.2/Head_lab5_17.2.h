#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <windows.h>
#include "Head_lab5_17.2.h" 

using namespace std;

struct Owner {
    string fullName;
    string carBrand;
    string carNumber;
};

void inputOwners(Owner* owners, int N);

bool containsDigits(const string& number, const string& digits);


Owner* filterOwnersByDigits(const Owner* owners, int N, int digits, int& filteredCount);

#endif // HEADER_H


