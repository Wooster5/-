#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N, nulcnt, maxnum, sumnum;
	cout << "Введите размер массива:";
	cin >> N;
	if (cin.fail())
	{
		cout << "Ошибка";
		return 0;
	}

	double* A = new double[N];
	double* pa = A;
	cout << "Исходный массив: ";
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		*(pa + i) = rand()*(-100-100)/RAND_MAX +100;
		cout << *(pa + i) << " ";
	}
	cout << endl;
	nulcnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (*(pa + i) == 0)
		{
			nulcnt++;
		}
	}
	cout << "Количество чисел раных 0: "<<nulcnt<<"\n";
	maxnum = *(pa+0);
	sumnum = 0;
	for (int i = 0; i < N; i++)
	{
		if (*(pa + i)>=maxnum)
		{	
			sumnum = 0;
			maxnum = *(pa + i);
		}else
		{
			sumnum = *(pa + i) + sumnum;
		}
	}
	cout << "Сумма элементов массива после последнего максимального элемента: " << sumnum << "\n";
	for (double* p = pa; p < pa + N - 1; p++)
	{
		for (double* q = p + 1; q < pa + N; q++)
		{
			if (abs(*q) > abs(*p))
			{
				swap(*p, *q);
			}
		}
	}
	cout << "Массив после сортировки по убыванию модулей элементов: ";
	for (int i = 0; i < N; i++)
	{
		cout << *(pa + i) << " ";
	}

	return 0;
}