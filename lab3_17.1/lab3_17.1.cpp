#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int num_cnt;
	string input_str;
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку: ";
	getline(cin, input_str);
	cout << "Вы ввели: " << input_str << endl;
	num_cnt = 0;

	
	for (char ch : input_str) 
	{
		if (isdigit(ch))
		{
			num_cnt++;
		}
	}
	cout << "Количество цифр: " << num_cnt;
	return 0;
}