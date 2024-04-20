#pragma once
#ifndef FACTORIES_H
#define FACTORIES_H
#include <iostream>
#include <string>
#include <math.h>
#include "Header_Lab5_17.1.h"

using namespace std;

struct factory
{
	string surname;
	int age;
	float salary;
	string speciality;
};

void FactoriesInf(factory* factories, int N);
void Factories35(const factory* factories, int N);
#endif // FACTORIES_H