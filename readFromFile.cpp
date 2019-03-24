#include "functions.h"

template < typename container >
void readFromFile(container students, container vargsiukai, const string& fileName) {
    ifstream fd (fileName);
//    students.reserve(30);

    string info;
    int gradeInt, maxString = 0;
    string gradeStr, message;
    student stud;

    if (fd.fail()) {
        cout << "Įvyko klaida atidarant duomenų failą. Prašome įsitikinti, ar failas tinkamoje direktorijoje." << endl;
        exit(EXIT_FAILURE);
    }

    std::getline(fd, info);

// Susižinome kiek pažymių gali būti daugiausiai faile
    std::istringstream reading(info);
    string testInfo;
    int gradesCount = -2;
    while(reading >> testInfo) { // einama, kol pasiekiamas eilutės galas
        gradesCount++;
    }
// Rezervuojame didžiausią galimą pažymių skaičių
    stud.grades.reserve(gradesCount);

    while (std::getline(fd, info)) {
        std::istringstream reading(info);

        reading >> stud.name;
        compareStrings(maxString, stud.name);

        reading >> stud.surname;
        compareStrings(maxString, stud.surname);

        // Klaidos žinutė
        message = "Pažymys studentui " + stud.name + " " + stud.surname + " neįrašytas. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. \n ARBA Įrašykite pažymį: ";

        while (!reading.eof()) { // kol nepasibaigs eilutė
            reading >> gradeStr;
            gradeInt = checkGrade(gradeStr, message);
            stud.grades.push_back(gradeInt);
        }
        checkGradesCount(stud.grades, stud.name, stud.surname);

        stud.exam = stud.grades.back();
        stud.grades.pop_back();
        stud.getGalutinis();
        stud.grades.clear();

        students.push_back(stud);
//        students.insert(students.end(), stud);
        stud = {};
    }
    fd.close();

    students.shrink_to_fit();
    sortStudents(students);

    Timer time;
    vargsiukai = iterpkKietus(students);
    cout << "Studentų filtravimas truko: " << time.elapsed()  << " s" << endl;

    printToFile(students, maxString, "kietuoliai.txt");
    printToFile(vargsiukai, maxString, "vargsiukai.txt");

    students.clear();
    vargsiukai.clear();
}