//
// Created by alex on 6. 08. 20.
//

#include "PersonGrade.h"
#include <sstream>

PersonGrade::PersonGrade() : day(0), month(0), grade(0) {
}

PersonGrade::PersonGrade(const int& d, const int& m, const int& g) : day(d), month(m), grade(g) {
}

PersonGrade::PersonGrade(const PersonGrade& pg) : day(pg.day), month(pg.month), grade(pg.grade) {
}

PersonGrade::~PersonGrade() {
}


// Set
void PersonGrade::set_day(const int &d) {
    this->day = d;
}

void PersonGrade::set_month(const int &m) {
    this->month = m;
}

void PersonGrade::set_grade(const int &g) {
    this->grade = g;
}

// Get
const int PersonGrade::get_day() const {
    return day;
}

const int PersonGrade::get_month() const {
    return month;
}

const int PersonGrade::get_grade() const {
    return grade;
}


const string PersonGrade::to_string() {
    stringstream ss;

    ss << "Day: " << day;
    ss << "\nMonth: " << month;
    ss << "\nGrade: " << grade;

    return ss.str();
}