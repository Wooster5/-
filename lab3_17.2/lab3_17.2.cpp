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
	cout << "������� ������: ";
	getline(cin, input_str);
	cout << "�� �����: " << input_str << endl;

	for (char& ch : input_str) 
	{
		if (isalpha(ch) && isupper(ch))
		{
			ch = tolower(ch);
		}
		
	}

	cout << "����� ������: "<<input_str;
	return 0;
}