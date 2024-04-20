#include "Header_Lab5_17.1.h"
#include <limits>

void FactoriesInf(factory* factories, int N)
{
	for (int i = 0; i < N; i++)
	{
        cout << "Введите фамилию " << i + 1 << ": ";
        cin >> factories[i].surname;
        for (char c : factories[i].surname) {
            if (c >= '0' && c <= '9') {
                cerr << "Ошибка ввода" << endl;
                exit(1);
            }
            if (c == ',' || c == '.' || c == '?' || c == '\\') {
                cerr << "Ошибка ввода" << endl;
                exit(1);
            }
        }

            cout << "Введите возраст " << i + 1 << ": ";
            double inputage;
            if (!(cin >> inputage) || inputage <= 0 || inputage != int(inputage)) {
                cerr << "Ошибка ввода" << endl;
                exit(1);
            }
            else 
            {
                factories[i].age = inputage;
            }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера

        cout << "Введите специальность " << i + 1 << ": ";
        getline(cin, factories[i].speciality);

            cout << "Введите зарплату " << i + 1 << ": ";
            cin >> factories[i].salary;
            if (cin.fail() || factories[i].salary <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода" << endl;
                exit(1);
            }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }
}
void Factories35(const factory* factories, int N)
{
    int r;
    r = 0;
	cout << "Фабрики на которых средний возраст больше 35 лет: " << endl;
	for (int i = 0; i < N; ++i)
	{
		if (factories[i].age > 35)
		{
			cout << i + 1 << endl;
            r += 1;
		}
        if (i==(N-1) && r==0)
        {
            cout <<"Таких заводов нет" << endl;
        }
	}
}

