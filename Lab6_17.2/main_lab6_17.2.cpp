#include "head_lab6_17.2.h"

int main() {
    setlocale(LC_ALL, "RU");
    string filename, word;
    filename ="test.txt";
    SetConsoleCP(1251);
    cout << "Введите слово: ";
    cin >> word;
    SetConsoleCP(866);

    int occurrences = countWordOccurrences(filename, word);
    if (occurrences == -1) {
        cout << "Ошибка открытия файла" << endl;
    }
    else if (occurrences == 0) {
        cout << "Слово \"" << word << "\" не было найдено в файле " << endl;
    }
    else {
        cout << "Слово \"" << word << "\" встречается " << occurrences << endl;
    }

    return 0;
}