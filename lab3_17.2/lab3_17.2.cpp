#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	int len_str;
	string input_str;
	setlocale(LC_ALL, "Russian");
	cout << "������� ������: ";
	getline(cin, input_str);
	cout << "�� �����: " << input_str << endl;

	for (char& ch : input_str) {
		ch = toupper(ch);
	}

	cout << "���������� ����: "<<input_str;
	return 0;
}