#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <locale>
#include <sstream>
#include <iomanip>

using namespace std;





bool isValidIP(const string& ip) {
    int num;
    char dot;
    stringstream ss(ip);
    int dotCount = 0;

    for (int i = 0; i < 4; ++i) {
        ss >> num;
        if (num < 0 || num > 255) return false;
        if (i < 3) {
            ss >> dot;
            if (dot != '.') return false;
            dotCount++;
        }
    }
    return dotCount == 3;
}


bool isValidTime(const string& time) {
    int hour, minute, second;
    char colon;
    stringstream ss(time);

    ss >> hour >> colon >> minute >> colon >> second;
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute > 59) return false;
    if (second < 0 || second > 59) return false;
    return true;
}


bool isValidDay(const string& day) {
    const string days[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
    for (const string& validDay : days) {
        if (day == validDay) {
            return true;
        }
    }
    return false;
}


void writeToFile(const string& filename, const map<string, int>& ipCounts) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Ошибка создания файла " << filename << "!" << endl;
        return;
    }

    for (const auto& pair : ipCounts) {
        outputFile << "IP: " << pair.first << ", Посещений: " << pair.second << endl;
    }

    outputFile.close();
    cout << "Файл " << filename << " успешно создан!" << endl;
}


void appendNumbersToFile(const string& filename) {
    ofstream outputFile(filename, ios::app);
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << " для дозаписи!" << endl;
        return;
    }

    
    outputFile << "\n10\n-5\n20\n-15\n30\n-25\n-7\n";
    outputFile.close();
}


int countNegativeNumbers(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << "!" << endl;
        return -1;
    }

    int negativeCount = 0;
    string line;
    while (getline(inputFile, line)) {
        
        if (line.find("IP:") != string::npos) continue;

        
        try {
            int num = stoi(line);
            if (num < 0) negativeCount++;
        }
        catch (const invalid_argument&) {
            
        }
    }

    inputFile.close();
    return negativeCount;
}

int main() {
    setlocale(LC_ALL, "rus");
    ifstream inputFile("visits.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла visits.txt!" << endl;
        return 1;
    }

    map<string, int> ipCounts;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string ip, time, day;

        ss >> ip >> time >> day;

        if (!isValidIP(ip)) {
            cerr << "Некорректный IP-адрес: " << ip << endl;
            continue;
        }
        if (!isValidTime(time)) {
            cerr << "Некорректное время: " << time << endl;
            continue;
        }
        if (!isValidDay(day)) {
            cerr << "Некорректный день недели: " << day << endl;
            continue;
        }

        string uniqueKey = ip + " " + time + " " + day;

        static map<string, bool> visitedKeys;
        if (!visitedKeys[uniqueKey]) {
            visitedKeys[uniqueKey] = true;
            ipCounts[ip]++;
        }
    }

    inputFile.close();

    
    writeToFile("unique_ips.txt", ipCounts);

    
    appendNumbersToFile("unique_ips.txt");

    
    int negativeCount = countNegativeNumbers("unique_ips.txt");
    if (negativeCount >= 0) {
        cout << "Количество отрицательных чисел в файле: " << negativeCount << endl;
    }

    return 0;
}