#include <iostream>
#include <string>
#include <cctype>
#include <locale>

using namespace std;
bool Palindrom(const string& s, int start, int end)
{
    if (start >= end) 
	{
        return true;
    }
    while (!isalnum(s[start]) && start < end) 
	{
        ++start;
    }
    while (!isalnum(s[end]) && start < end) 
	{
        --end;
    }
    if (tolower(s[start]) != tolower(s[end])) 
	{
        return false; 
    }
    return Palindrom(s, start + 1, end - 1);
}

int main()
{
	locale::global(locale("Russian_Russia.1251"));
	for (int i = 1; i <= 5; i++)
	{
		cout << "Введите слово "<<i<<": ";
		string word;
		cin >> word;


		if (Palindrom(word, 0, word.length()-1))
		{
			cout << "Да, это палиндром.\n";
		}
		else
		{
			cout << "Нет, это не палиндром.\n";

		}
	}



	return 0;

}