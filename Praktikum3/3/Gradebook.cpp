#include "Gradebook.hpp"

void Gradebook::addOrUpdateStudent(const string &studentName, double grade) {
    studentGrades[studentName] = grade;;
}

bool Gradebook::removeStudent(const string &studentName) {
    if (studentExists(studentName)) {
        studentGrades.erase(studentName);
        return true;
    } else {
        return false;
    }
}

bool Gradebook::getGrade(const string &studentName, double &grade) const {
    if (studentExists(studentName)) {
        grade = studentGrades.at(studentName);
        return true;
    } else {
        return false;
    }
}

bool Gradebook::studentExists(const string &studentName) const {
    return studentGrades.find(studentName) != studentGrades.end();
}

void Gradebook::printGrades() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong" << endl;
    } else {
        int i = 1;
        for (const auto &entry : studentGrades) {
            cout << i++ << ". " << entry.first << ": " << entry.second << endl;
        }
    }
}

void Gradebook::printGradesRank() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong" << endl;
    } else {
        vector<pair<string, double>> sortedGrades(studentGrades.begin(), studentGrades.end());
        sort(sortedGrades.begin(), sortedGrades.end(), [](const pair<string, double> &a, const pair<string, double> &b) {
            return a.second > b.second; // urutkan berdasarkan nilai terbesar ke terkecil
        });
        int i = 1;
        for (const auto &entry : sortedGrades) {
            cout << i++ << ". " << entry.first << ": " << entry.second << endl;
        }
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> result;
    for (const auto &entry : studentGrades) {
        if (entry.second > threshold) {
            result.push_back(entry.first);
        }
    }
    sort(result.begin(), result.end()); // urutkan berdasarkan abjad
    return result;
}

double Gradebook::getAverageGrade() const {
    if (studentGrades.empty()) {
        return 0.0;
    } else {
        double total = 0.0;
        for (const auto &entry : studentGrades) {
            total += entry.second;
        }
        return total / studentGrades.size();
    }
}

size_t Gradebook::getNumberOfStudents() const {
    return studentGrades.size();
}