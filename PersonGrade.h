//
// Created by alex on 6. 08. 20.
//

#ifndef TASK0202_PERSONGRADE_H
#define TASK0202_PERSONGRADE_H
#include <iostream>

using namespace std;

class PersonGrade {
private:
    int day, month, grade;

public:
    PersonGrade();
    PersonGrade(const int& d, const int& m, const int& g);
    PersonGrade(const PersonGrade& pg);
    ~PersonGrade();

    // Set
    void set_day(const int& d);
    void set_month(const int& m);
    void set_grade(const int& g);

    // Get
    const int get_day() const;
    const int get_month() const;
    const int get_grade() const;
    const string to_string();
};


#endif //TASK0202_PERSONGRADE_H
