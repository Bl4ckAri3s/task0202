#include <iostream>
#include <vector>
#include <random>
#include "PersonGrade.h"

using namespace std;

void menu() {
    cout << "=========================" << endl;
    cout << "======== MENU: ==========" << endl;
    cout << "=========================" << endl;
    cout << "1 ... GENERATE GRADES" << endl;
    cout << "2 ... PRINT GRADES" << endl;
    cout << "3 ... PRINT AVERAGE GRADE" << endl;
    cout << "4 ... PRINT GRADES ABOVE AVERAGE" << endl;
    cout << "5 ... PRINT POSITIVE GRADES" << endl;
    cout << "6 ... PRINT NUMBER OF EACH GRADE" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "=========================" << endl;
    cout << "Select: ";
}

void fillArrayOfGrades(vector<PersonGrade*>& grades, const int& number_of_grades) {
    random_device rd;
    uniform_int_distribution<int> dist_month(1, 12);
    uniform_int_distribution<int> dist_grade(1, 10);

    for (int i = 0; i < number_of_grades; i++)
        grades.push_back(new PersonGrade(i + 1, dist_month(rd), dist_grade(rd)));
}

void printArrayOfGrades(const vector<PersonGrade*>& grades) {
    cout << "Grades: ";
    for (int i = 0; i < grades.size(); i++)
        cout << ((i > 0) ? ", " : "") << grades[i]->get_grade();

    cout << "." << endl;
}

int getAverageGrade(const vector<PersonGrade*>& grades) {
    int sum = 0;
    for (const auto& person : grades)
        sum += person->get_grade();

    return (sum / grades.size());
}

void printAboveAverageGrades(const vector<PersonGrade*>& grades) {
    int averageGrade = getAverageGrade(grades);

    cout << "Grades above average: ";
    for (const auto& person : grades) {
        if (person->get_grade() > averageGrade)
            cout << person->get_grade() << ", ";
    }
}

void printPositiveGrades(const vector<PersonGrade*>& grades) {
    cout << "Positive grades: ";

    for (const auto& person : grades) {
        if (person->get_grade() > 5)
            cout << person->get_grade() << ", ";
    }
}

void printNumberOfEachGrade(const vector<PersonGrade*>& grades) {
    int number_of_each_grade[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (const auto& person : grades)
        number_of_each_grade[person->get_grade() - 1]++;


    cout << "Number of each grade: \n";
    for (int i = 0; i < 10; i++)
        cout << "Grade " << i + 1 << ": " << number_of_each_grade[i] << endl;

}


int main() {
    vector<PersonGrade*> grades;
    int number_of_grades = 30;

    bool running = true;
    int selection;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                fillArrayOfGrades(grades, number_of_grades);
                break;
            case 2:
                printArrayOfGrades(grades);
                break;
            case 3:
                cout << "Average grade is: " << getAverageGrade(grades);
                break;
            case 4:
                printAboveAverageGrades(grades);
                break;
            case 5:
                printPositiveGrades(grades);
                break;
            case 6:
                printNumberOfEachGrade(grades);
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);


    for (auto& elt : grades)
        delete elt;

    return 0;
}