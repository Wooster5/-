#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	int len_str;
	string input_str;
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку: ";
	getline(cin, input_str);
	cout << "Вы ввели: " << input_str << endl;

	for (char& ch : input_str) {
		ch = toupper(ch);
	}

	cout << "Количество цифр: "<<input_str;
	return 0;
}