#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "������� ������ �������:";
	cin >> N;
	if (cin.fail())
	{
		cout << "������";
		return 0;
	}
	
	int* A = new int[N];
	int* pa = A;
	cout << "�������� ������: ";
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		*(pa+i)= rand() % 100 + 1;
		cout <<*(pa+i)<< " ";     
	}
	cout<<endl;
	cout << "׸���� ����� � ������� ����������� �� ��������: ";
	for (int i = 0; i < N; i++)
	{
		if (*(pa+i) % 2 == 0)
		{
			cout <<*(pa+i)<<" ";
		}
	}
	cout << "\n";
	cout << "�������� ����� � ������� �������� �� �������� : ";
	for (int i = N-1; i >= 0; i--)
	{

		if (*(pa + i) % 2 != 0)
		{
			cout << *(pa + i) << " ";

		}
	}
		

	return 0;
}