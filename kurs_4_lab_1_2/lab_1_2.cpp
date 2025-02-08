#include <iostream>
#include <set>
using namespace std;

// Функция для получения корректного числа в диапазоне [1, 9]
int Input(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 1 || value > 9) {
            cout << "Ошибка: введите число от 1 до 9." << endl;
            cin.clear(); // Очищаем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
        else {
            break;
        }
    }
    return value;
}

// Функция для получения точек прямоугольника
set<pair<int, int>> Intersec(int x1, int y1, int x2, int y2) {
    set<pair<int, int>> points;
    for (int x = min(x1, x2); x <= max(x1, x2); x++) {
        for (int y = min(y1, y2); y <= max(y1, y2); y++) {
            points.insert({ x, y });
        }
    }
    return points;
}

int main() {
    setlocale(LC_ALL, "rus");

    // Ввод координат первого прямоугольника
    cout << "Введите координаты первого прямоугольника:" << endl;
    int x1 = Input("x1: ");
    int y1 = Input("y1: ");
    int x2 = Input("x2: ");
    int y2 = Input("y2: ");

    // Ввод координат второго прямоугольника
    cout << "Введите координаты второго прямоугольника:" << endl;
    int x3 = Input("x3: ");
    int y3 = Input("y3: ");
    int x4 = Input("x4: ");
    int y4 = Input("y4: ");

    // Получение множеств точек для каждого прямоугольника
    set<pair<int, int>> A = Intersec(x1, y1, x2, y2);
    set<pair<int, int>> B = Intersec(x3, y3, x4, y4);

    // Поиск пересечения множеств точек
    set<pair<int, int>> intersection;
    for (const auto& p : A) {
        if (B.count(p)) {
            intersection.insert(p);
        }
    }

    // Вывод результатов
    if (!intersection.empty()) {
        cout << "Прямоугольники пересекаются. Общие точки:" << endl;
        for (const auto& p : intersection) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
    else {
        cout << "Прямоугольники не пересекаются." << endl;
    }

    return 0;
}