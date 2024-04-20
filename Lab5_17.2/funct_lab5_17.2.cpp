#include "Head_lab5_17.2.h" 

void inputOwners(Owner* owners, int N) 
{
    for (int i = 0; i < N; ++i) 
    {
        cout << "Владелец " << i + 1 << ":\n";
        cout << "ФИО: ";
        cin.ignore();
        getline(cin, owners[i].fullName);
        cout << "Марка машины: ";
        getline(cin, owners[i].carBrand);
        cout << "Номер машины: ";
        getline(cin, owners[i].carNumber);
    }
}
bool containsDigits(const string& number, int digits) 
{
    string digitsStr = to_string(digits);
    for (char digit : digitsStr) 
    {
        if (number.find(digit) == string::npos) 
        {
            return false;
        }
    }
    return true;
}

Owner* filterOwnersByDigits(const Owner* owners, int N, int digits, int& filteredCount) 
{
    filteredCount = 0;
    for (int i = 0; i < N; ++i) 
    {
        if (containsDigits(owners[i].carNumber, digits)) 
        {
            ++filteredCount;
        }
    }

    Owner* filteredOwners = new Owner[filteredCount];
    int index = 0;
    for (int i = 0; i < N; ++i) 
    {
        if (containsDigits(owners[i].carNumber, digits)) 
        {
            filteredOwners[index++] = owners[i];
        }
    }

    return filteredOwners;
}



