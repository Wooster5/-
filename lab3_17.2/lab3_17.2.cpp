#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string input_str;
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку: ";
	getline(cin, input_str);
	cout << "Вы ввели: " << input_str << endl;

	for (char& ch : input_str) 
	{
		if (isalpha(ch) && isupper(ch))
		{
			ch = tolower(ch);
		}
		
	}

	cout << "Новая строка: "<<input_str;
	return 0;
}