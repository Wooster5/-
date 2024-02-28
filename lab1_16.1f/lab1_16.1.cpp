//
//#include <iostream>
//#include <cmath>
//#include  <ctype.h>
//#include  <cmath>
//using namespace std;
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    float  x, y, z;
//    float  sum, S;
//    cout << "¬ведите x:" << endl;
//    cin >> x;
//    if (cin.fail())
//    {
//        cout << "ошибка";
//        return 0;
//    }
//
//    cout << "¬ведите y:" << endl;
//    cin >> y;
//    if (cin.fail())
//    {
//        cout << "ошибка";
//        return 0;
//    }
//    cout << "¬ведите z:" << endl;
//    cin >> z;
//    if (cin.fail())
//    {
//        cout << "ошибка";
//        return 0;
//    }
//    sum = (x + y + z) / 2;
//    S = sqrt(sum * (sum - x) * (sum - y) * (sum - z));
//    if (x + y < z || x + z < y || y + z < x) {
//        cout << "“реугольник не может существовать" << endl;
//    }
//    else {
//        cout << "площадь треугольника:" << S;
//    }
//
//
//
//    return 0;
//
//
//}




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
        cout << "ошибка";
        return 0;
    }
    if (x > 2) {
        y = 5 * x + sqrt(pow(x, 2) + x);
        cout << "y=" << y;
    }
    else if (x = 2) {
        y = 9 * x - sin(3 * pow(x, 4) - 1);
        cout << "y=" << y;
    }
    else {
        y = exp(-2 * x) + cos(2 * x);
        cout << "y=" << y;
    }

    return 0;
}

