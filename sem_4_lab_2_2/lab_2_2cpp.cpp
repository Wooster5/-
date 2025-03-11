#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <set>
#include <sstream>
#include <algorithm> 
#include <cctype>    
using namespace std;


bool isInteger(const string& input) {
    for (char ch : input) {
        if (!isdigit(ch) && ch != '-') {
            return false;
        }
    }
    return true;
}


int getValidLength() {
    string input;
    int length = 0;

    while (true) {
        cout << "Введите длину строки (целое число больше 0): ";
        cin >> input;

        
        if (isInteger(input)) {
            length = stoi(input);
            if (length > 0) {
                break; 
            }
            else {
                cout << "Ошибка! Число должно быть больше 0." << endl;
            }
        }
        else {
            
            try {
                double temp = stod(input);
                length = static_cast<int>(round(temp));
                if (length > 0) {
                    cout << "Введено вещественное число. Округлено до: " << length << endl;
                    break;
                }
                else {
                    cout << "Ошибка! Число должно быть больше 0." << endl;
                }
            }
            catch (invalid_argument&) {
                cout << "Ошибка! Введите корректное число." << endl;
            }
        }
    }

    return length;
}


string processString(const string& str, int length) {
    if (str.length() > length) {
        return str.substr(0, length);
    }
    else {
        return str + string(length - str.length(), '*');
    }
}


int countUniqueWords(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Ошибка! Не удалось открыть файл " << filename << "." << endl;
        return -1;
    }

    set<string> uniqueWords; 
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;

        while (ss >> word) {
            // Удаляем знаки препинания
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            // Приводим слово к нижнему регистру
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            
            uniqueWords.insert(word);
        }
    }

    inputFile.close();
    return uniqueWords.size(); 
}

int main() {
    
    setlocale(LC_ALL, "rus");

    ifstream inputFile("input1.txt");
    if (!inputFile.is_open()) {
        cout << "Ошибка! Не удалось открыть файл input.txt." << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Ошибка! Не удалось создать файл output.txt." << endl;
        return 1;
    }

    int length = getValidLength();

    string line;
    while (getline(inputFile, line)) {
        string processedLine = processString(line, length);
        outputFile << processedLine << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Файл output.txt успешно создан!" << endl;

    int uniqueWordCount = countUniqueWords("input.txt");
    if (uniqueWordCount != -1) {
        cout << "Количество уникальных слов в файле: " << uniqueWordCount << endl;
    }

    return 0;
}