#ifndef HEADER_H

#define HEADER_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
using std::cout; using std::cin; using std::endl; using std::string; using std::setw; using std::left; using std::setprecision; using std::fixed;
using std::sort; using std::stoi; using std::vector; using std::ifstream;

void wasStringGivenInsteadInt(int &param) {
    while (cin.fail()) { // ciklas, kol bus įvestas skaičius
        cout << "Parametras neįrašytas. Prašome pateikti teisingą parametrą: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> param;
    }
}

struct student {
    string name = "Vardenis";
    string surname = "Pavardenis";
    vector<int> grades;
    int exam=0;
    double galutinis=0; // Galutinis studento pažymys
    double galutinisMedian = 0;
    int numberOfGrades=0;

    void getGrades() {
        grades.reserve(5);
        int input;
        cout << "Pažymys: ";
        cin >> input;
        numberOfGrades = -1;
        while (cin.good()) { // Ciklas, kol nebus įvestas simbolis n ir baigtas studentų įrašymas
            while(input > 10) {
                cout << "Parametras neįrašytas. Prašome pateikti teisingą parametrą: " << endl;
                cout << "Pažymys: ";
                cin >> input;
            }
            numberOfGrades++;
            grades.push_back(input);
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Pažymys: ";
            cin >> input;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        numberOfGrades++; // Šis kintamasis toliau naudojamas kaip masyvo elementų skaičius, kuris turi būti didesnis nei auksčiausias masyvo elementų indeksas
    }
    float getAverage() {
        int sum = 0;
        float average;
        for ( auto &grade : grades) { // pereina per kiekvieną pažymį
            sum += grade;
        }
        average = (float)sum/grades.size();
        return average;
    }
    float getMedian() {
        sort(grades.begin(), grades.end());
        float median;
        int middleIndex = (double) grades.size()/2;
        if (grades.size() == 1) {
            median = grades[0];
        } else if (grades.size() % 2 == 0) {
            median = (float)(grades[middleIndex] + grades[--middleIndex])/2;
        } else {
            median = grades[--middleIndex];
        }
        return median;
    }
    void getGalutinis() {
        float multiplier;
        multiplier = getAverage();
        galutinis = 0.4 * multiplier + 0.6 * exam;
        multiplier = getMedian();
        galutinisMedian = 0.4 * multiplier + 0.6 * exam;
    }
    void generateGrades() {
        cout << "Kiek pažymių generuoti? ";
        cin >> numberOfGrades;
        wasStringGivenInsteadInt(numberOfGrades);
        grades.reserve(numberOfGrades);
        const unsigned int seed = time(0);
        std::mt19937_64 rng(seed);
        std::uniform_int_distribution<> random(1, 10);
        for (int i=0; i<numberOfGrades; i++) { // pereina per kiekvieną pažymį
            grades.push_back(random(rng));
//            cout << grades[i] << " ";
        }
//        cout << endl;
        exam = random(rng);
    }
};
// Globalūs kintamieji
vector<student> students;
int maxString = 0; // Ilgiausia simbolių eilutė rezultatų spausdinimui

#endif