#include "Header_Lab5_17.1.h"
int main() 
{
	setlocale(LC_ALL, "rus");
	double inputN;
	cout << "������� ���������� �������: ";
	if (!(cin >> inputN) || inputN <= 0 || inputN != int(inputN)) {
		cerr << "������ �����" << endl;
		return 1;
	}
	int N = inputN;

	factory* factories = new factory[N];
	FactoriesInf(factories, N);
	Factories35(factories, N);
	return 0;
}