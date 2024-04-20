#include "Header_Lab5_17.1.h"
#include <limits>

void FactoriesInf(factory* factories, int N)
{
	for (int i = 0; i < N; i++)
	{
        cout << "������� ������� " << i + 1 << ": ";
        cin >> factories[i].surname;
        for (char c : factories[i].surname) {
            if (c >= '0' && c <= '9') {
                cerr << "������ �����" << endl;
                exit(1);
            }
            if (c == ',' || c == '.' || c == '?' || c == '\\') {
                cerr << "������ �����" << endl;
                exit(1);
            }
        }

            cout << "������� ������� " << i + 1 << ": ";
            double inputage;
            if (!(cin >> inputage) || inputage <= 0 || inputage != int(inputage)) {
                cerr << "������ �����" << endl;
                exit(1);
            }
            else 
            {
                factories[i].age = inputage;
            }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������

        cout << "������� ������������� " << i + 1 << ": ";
        getline(cin, factories[i].speciality);

            cout << "������� �������� " << i + 1 << ": ";
            cin >> factories[i].salary;
            if (cin.fail() || factories[i].salary <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������ �����" << endl;
                exit(1);
            }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������
    }
}
void Factories35(const factory* factories, int N)
{
    int r;
    r = 0;
	cout << "������� �� ������� ������� ������� ������ 35 ���: " << endl;
	for (int i = 0; i < N; ++i)
	{
		if (factories[i].age > 35)
		{
			cout << i + 1 << endl;
            r += 1;
		}
        if (i==(N-1) && r==0)
        {
            cout <<"����� ������� ���" << endl;
        }
	}
}

