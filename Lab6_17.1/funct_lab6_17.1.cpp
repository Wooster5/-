#include "head_lab6_17.1.h"


void readTriangles(const string& filename, Triangle* triangles, int& count) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка";
    }

    count = 0;
    double side1, side2, side3;
    while (file >> side1 >> side2 >> side3) {
        if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1){
            triangles[count++] = { side1, side2, side3 };
        }
        else {
            cout << "Найден неправильный треугольник. Пропускаем." << endl;
        }
    }

    file.close();
}


void calculateProperties(const Triangle* triangles, double* perimeters, double* areas, int count) {
    for (int i = 0; i < count; ++i) {
        double semiPerimeter = (triangles[i].a + triangles[i].b + triangles[i].c) / 2;
        perimeters[i] = semiPerimeter * 2;
        double area = sqrt(semiPerimeter * (semiPerimeter - triangles[i].a) * (semiPerimeter - triangles[i].b) * (semiPerimeter - triangles[i].c));
        areas[i] = area;
    }
}


void writeResults(const string& filename, const Triangle* triangles, const double* perimeters, const double* areas, int count) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Невозможно открыть файл: " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < count; ++i) {
        file << "Треугольник " << i + 1 << ": стороны = " << triangles[i].a << ", " << triangles[i].b << ", " << triangles[i].c
            << ", периметр = " << perimeters[i] << ", площадь = " << areas[i] << endl;
    }

    file.close();
}
