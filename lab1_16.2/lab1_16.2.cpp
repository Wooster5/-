#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
    int x;
    double y;
    cout << "¬ведите x:" << endl;
    cin >> x;
    if (cin.fail())
    {
        cout << "ошибка" << endl;
        return 0;
    }
    if (x > 2) {
        y = 5 * x + sqrt(pow(x, 2) + x);
        cout << "y=" << y << endl;
    }
    else if (x==2){
        y = 9 * x - sin(3 * pow(x, 4) - 1);
        cout << "y=" << y << endl;
    }
    else {
        y = exp(-2 * x) + cos(2 * x);
        cout << "y=" << y << endl;
    }

	return 0;
}