#ifndef FUNCTIONS_H

#define FUNCTIONS_H

int checkGrade(string &param, const string& message);
void checkGradesCount(vector<int>& grades, const string& fname, const string& lname);

template <typename container>
void speedTest(container students, container vargsiukai);

void compareStrings(int& base, const string& string);
bool sortByName(const student & stud1, const student & stud2);

template <typename container>
void sortStudents(container &students);

void printResult(vector<student>students, int maxString);
bool gavoSkola (const student & stud);
vector<student> raskMinkstus(vector<student> &students);
vector<student> iterpkKietus(vector<student> &students);
void generateFile(string fileName, int size);

template <typename container>
void printToFile (const container &students, int maxString, string fileName);

#include "functions.cpp"

#endif