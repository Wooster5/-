#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите размер массива:";
	cin >> N;
	if (cin.fail())
	{
		cout << "Ошибка";
		return 0;
	}
	
	int* A = new int[N];
	int* pa = A;
	cout << "Исходный массив: ";
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		*(pa+i)= rand() % 100 + 1;
		cout <<*(pa+i)<< " ";     
	}
	cout<<endl;
	cout << "Чётные числа в порядке возрастания их индексов: ";
	for (int i = 0; i < N; i++)
	{
		if (*(pa+i) % 2 == 0)
		{
			cout <<*(pa+i)<<" ";
		}
	}
	cout << "\n";
	cout << "Нечётные числа в порядке убывания их индексов : ";
	for (int i = N-1; i >= 0; i--)
	{

		if (*(pa + i) % 2 != 0)
		{
			cout << *(pa + i) << " ";

		}
	}
		

	return 0;
}