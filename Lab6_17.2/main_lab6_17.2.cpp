#include "head_lab6_17.2.h"

int main() {
    setlocale(LC_ALL, "RU");
    string filename, word;
    filename ="test.txt";
    SetConsoleCP(1251);
    cout << "������� �����: ";
    cin >> word;
    SetConsoleCP(866);

    int occurrences = countWordOccurrences(filename, word);
    if (occurrences == -1) {
        cout << "������ �������� �����" << endl;
    }
    else if (occurrences == 0) {
        cout << "����� \"" << word << "\" �� ���� ������� � ����� " << endl;
    }
    else {
        cout << "����� \"" << word << "\" ����������� " << occurrences << endl;
    }

    return 0;
}