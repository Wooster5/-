#include <iostream>
#include <set>
#include<string>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    set<char> symbols = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*' };
    string s;

    cout << "Введите строку: ";
    getline(cin, s);

    int count = 0;
    for (char c : s) {
        if (symbols.count(c)) {
            count++;
        }
    }

    cout << "Общее количество цифр и знаков (+, -, *): " << count << endl;

    return 0;
}
