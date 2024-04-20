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
	cout << "Введите 5 элементов для рассчёта чисел Фибоначчи: "<<endl;
	for (int N = 0; N<5; N++)
	{
		cout << N+1 << " элемент последовательности: ";
		cin >> numbers[N];
		if (!cin) {
			cout << "Ошибка ввода" << endl;
			return 1;
		}
		R= numbers[N];
		/*if (cin.fail() || R < 1)
		{
			cout << "Ошибка ввода" << endl;
			return 1;
		}*/
		cout <<R<<" элемент последовательности чисел Фибоначчи="<<Fib(R) <<endl;
	}
	return 0;
}