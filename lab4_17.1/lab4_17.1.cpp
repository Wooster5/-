#include <iostream>

using namespace std;
int Fib(int N)
{
	int FK;
	int FK1;
	int FK2;
	FK = 1;
	FK1 = 0;
	FK2 = 0;
	if (N == 1 || N == 2) 
	{
		 FK = 1;
	}
	if (N > 2)
	{
		FK1 = FK;
		FK2 = FK;
		for (int i = 2; i < N; i++)
		{
			FK = FK1 + FK2;
			FK2 = FK1;
			FK1 = FK;
		}
	}
	return FK;
}
int main()
{
	int R;
	int numbers[5];
	locale::global(locale("Russian_Russia.1251"));
	cout << "������� 5 ��������� ��� �������� ����� ���������: "<<endl;
	for (int N = 0; N<5; N++)
	{
		cout << N+1 << " ������� ������������������: ";
		cin >> numbers[N];
		if (!cin) {
			cout << "������ �����" << endl;
			return 1;
		}
		R= numbers[N];
		/*if (cin.fail() || R < 1)
		{
			cout << "������ �����" << endl;
			return 1;
		}*/
		cout <<R<<" ������� ������������������ ����� ���������="<<Fib(R) <<endl;
	}
	return 0;
}