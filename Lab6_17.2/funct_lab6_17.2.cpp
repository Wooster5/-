#include "head_lab6_17.2.h"

int countWordOccurrences(const string& filename, const string& word) {
    ifstream file(filename);
    if (!file) {
        cerr << "Невозможно открыть файл: " << filename << endl;
        return -1; // Возвращаем -1 в случае ошибки открытия файла
    }

    int count = 0;
    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
    }

    file.close();
    return count;
}