#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int num_cnt;
	string input_str;
	setlocale(LC_ALL, "Russian");
	cout << "������� ������: ";
	getline(cin, input_str);
	cout << "�� �����: " << input_str << endl;
	num_cnt = 0;

	
	for (char ch : input_str) 
	{
		if (isdigit(ch))
		{
			num_cnt++;
		}
	}
	cout << "���������� ����: " << num_cnt;
	return 0;
}