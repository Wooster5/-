#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

struct Triangle {
    double a, b, c;  
};

void readTriangles(const string& filename, Triangle* triangles, int& count);
void calculateProperties(const Triangle* triangles, double* perimeters, double* areas, int count);
void writeResults(const string& filename, const Triangle* triangles, const double* perimeters, const double* areas, int count);

#endif // TRIANGLE_H



