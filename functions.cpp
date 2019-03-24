
void compareStrings(int& base, const string& string) {
    if (base < string.size()) {
        base = string.size();
    }
}
bool sortByName(const student & stud1, const student & stud2) {
    return (stud1.name < stud2.name) ||
           ((stud1.name == stud2.name) && (stud1.surname > stud2.surname));
}

template <typename container>
void sortStudents(container &students) {
    sort(students.begin(), students.end(), sortByName);
}
void printResult(vector<student>students, int maxString) {
    for (auto &student : students) {
        student.getGalutinis();
        float multiplier = student.getMedian();
        student.galutinisMedian = 0.4 * multiplier + 0.6 * student.exam;
    }
    cout << left << setw(maxString+20) << "Vardas" << setw(maxString+20) << "Pavardė" << setw(maxString+20) << "Galutinis (Vid.)" << setw(maxString+20) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 4*(maxString+20); i++) cout << "-";
    cout << endl;
    sortStudents(students);

    std::streamsize prec = cout.precision();

    for (auto &student : students) {
        cout << setw(maxString+20) << student.name
             << setw(maxString+20) << student.surname
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinis
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinisMedian
             << setprecision(prec) << endl;
    }
}

template <typename container>
void printToFile (const container &students, int maxString, string fileName) {
    std::ofstream file (fileName);

    file << left << setw(maxString+20) << "Vardas" << setw(maxString+20) << "Pavardė" << setw(maxString+20) << "Galutinis (Vid.)" << setw(maxString+20) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 4*(maxString+20); i++) {
    file << "-";
    }
    file << endl;

    std::streamsize prec = file.precision();

    for (auto &student : students) {
        file << setw(maxString + 20) << student.name
             << setw(maxString + 20) << student.surname
             << setw(maxString + 20) << setprecision(2) << fixed << student.galutinis
             << setw(maxString + 20) << setprecision(2) << fixed << student.galutinisMedian
             << setprecision(prec) << endl;
    }
    file.close();
}

// Patikrina, ar studentas gavo skolą (yra vargšiukas)
bool gavoSkola (const student & stud) {
    if (stud.galutinis < 5) {
        return true;
    }
        return false;
}

// minkštus studentus nukopijuoja į naują vektorių ir ištrina iš seno
vector<student> raskMinkstus(vector<student> &students) {
    vector<student> minksti;
    vector<student>::size_type i = 0;

    // invariantas: vektoriaus `studentai` elementai [0, i) yra "kieti"
    while (i != students.size()) {
        if (gavoSkola(students[i])) {
            minksti.push_back(students[i]);
            students.erase(students.begin() + i);  // ištrinti i-ąjį stud.
        } else
            ++i;  // pereiti prie kito studento
    }
    return minksti;  // grąžina studentus gavusius skolą
}

vector<student> iterpkKietus(vector<student> &students) {
    vector<student> minksti;
    vector<student>::size_type i = 0;
    int bound = 0; // nuo kurios vietos vektoriuje pasibaigia "kieti" studentai
    student stud; // laikinas studento elementas

    // invariantas: vektoriaus `studentai` elementai [0, i) yra "kieti"
    while (i != students.size()) {
        stud = students[i];
        if (gavoSkola(stud)) {
            minksti.push_back(stud);
        } else {
            students.insert(students.begin(), stud); // iterpia negavusį skolos studentą į pradžią
            bound++;
            ++i;  // eilė pasislenka, taigi, indeksas irgi turi pasislinkti
        }
        ++i;  // pereiti prie kito studento
    }

    if (bound != 0)
        students.resize( bound );

    students.shrink_to_fit();
    return minksti;  // grąžina studentus gavusius skolą
}

deque<student> iterpkKietus(deque<student> &students) {
    deque<student> minksti;
    deque<student>::size_type i = 0;
    int bound = 0; // nuo kurios vietos vektoriuje pasibaigia "kieti" studentai
    student stud; // laikinas studento elementas

    // invariantas: vektoriaus `studentai` elementai [0, i) yra "kieti"
    while (i != students.size()) {
        stud = students[i];
        if (gavoSkola(stud)) {
            minksti.push_back(stud);
        } else {
            students.push_front( stud ); // iterpia negavusį skolos studentą į pradžią
            bound++;
            ++i;  // eilė pasislenka, taigi, indeksas irgi turi pasislinkti
        }
        ++i;  // pereiti prie kito studento
    }

    if (bound != 0)
        students.resize( bound );

    students.shrink_to_fit();
    return minksti;  // grąžina studentus gavusius skolą
}


void generateFile(string fileName, int size) {
    const unsigned int seed = time(0);
    std::mt19937_64 rng(seed);
    std::uniform_real_distribution<double> random(1, 10);

    std::ofstream file (fileName);

    cout << "Generuojamas failas " << fileName;

    file << left << setw(30) << "Vardas" << setw(30) << "Pavardė" << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5" << setw(5) << "EGZ"<< endl;

    for (int i = 0; i<size; i++) {
        file << left << setw(30) << ("Vardas" + std::to_string(i+1)) << setw(30) << ("Pavardė" + std::to_string(i+1)) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng)  << setw(5) << (int)random(rng) << endl;
    }

    cout << "BAIGTA" << endl;

    file.close();
}

// Patikrina, ar pažymys yra skaičius ir ar tinkamas kaip pažymys
int checkGrade(string &param, const string& message) {
    int paramInt;

    try {
        paramInt = std::stoi(param);

        while(paramInt > 10) { // Ar atitinka dešimtbalę sistemą?
            cout << message << endl;
            cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
            cout << "Pažymys: ";
            cin >> paramInt;
            wasStringGivenInsteadInt(paramInt);
        }

    } catch (const std::invalid_argument & e) {
        cout << message;
        cin >> paramInt;
        wasStringGivenInsteadInt(paramInt);

        while(paramInt > 10) { // Ar atitinka dešimtbalę sistemą?
            cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
            cout << "Pažymys: ";
            cin >> paramInt;
            wasStringGivenInsteadInt(paramInt);
        }
    }

    return paramInt;
}

// Ar pažymių užtenka, nes paskutinis pažymys visada bus egzaminas
void checkGradesCount(vector<int>& grades, const string& fname, const string& lname) {
    int grade;

    if (grades.size() <= 1) {
        cout << "Studentui " << fname << " " << lname << " trūksta pažymių, įrašykite dar egzamino pažymį. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. ARBA \n";

        // Prašoma įvesti du pažymius
        for (int i = 1; i <= 2; i++) {
            cout << "Įrašykite pažymį: ";
            cin >> grade;
            wasStringGivenInsteadInt(grade);

            while (grade > 10) { // Ar atitinka dešimtbalę sistemą?
                cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
                cout << "Pažymys: ";
                cin >> grade;
                wasStringGivenInsteadInt(grade);
            }

            grades.push_back(grade);
        }
    }
}