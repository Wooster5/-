#include "head_lab6_17.1.h"

int main()
{
	setlocale(LC_ALL, "RU");
    const int MAX_TRIANGLES = 100;
    Triangle triangles[MAX_TRIANGLES];
    double perimeters[MAX_TRIANGLES], areas[MAX_TRIANGLES];
    int count;

    readTriangles("triangles.txt", triangles, count);
    calculateProperties(triangles, perimeters, areas, count);
    writeResults("results.txt", triangles, perimeters, areas, count);

    cout << "результаты сохранены в 'results.txt'" << endl;

    return 0;

}