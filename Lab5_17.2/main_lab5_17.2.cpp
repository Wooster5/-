#include "Head_lab5_17.2.h"
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	double inputN;
	cout << "������� ���������� ����������: ";
	if (!(cin >> inputN) || inputN <= 0 || inputN != int(inputN)) {
		cerr << "������ �����" << endl;
		return 1;
	}
	int N = inputN;
	double inputdigits;
	
	cout << "������� �����: ";
	if (!(cin >> inputdigits) || inputdigits <= 0 || inputdigits != int(inputdigits)) {
		cerr << "������ �����" << endl;
		return 1;
	}
	int digits = inputdigits;
	Owner* owners = new Owner[N];
	inputOwners(owners, N);
	int filteredCount;
	Owner* filteredOwners = filterOwnersByDigits(owners, N, digits, filteredCount);

	int r, f;
	r = 0;
	cout << "\n��������������� ���������:\n";
	for (int i = 0; i < filteredCount; ++i) 
	{
		cout << "���: " << filteredOwners[i].fullName << "\n";
		cout << "����� ������: " << filteredOwners[i].carBrand << "\n";
		cout << "����� ������: " << filteredOwners[i].carNumber << "\n\n";
		r = r + 1;
		f = i;
	}
	if (r == 0)
	{
		cout << "����� ���������� ��� " << endl;
	}

	return 0;
}
