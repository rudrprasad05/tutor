#include "Student.h"

using namespace std;
// Constructor
Student::Student(string sid, int smarks) {
    this->id = sid;
    this->marks = smarks;
    grade = determine_grade(marks);
}

// Destructor
Student::~Student() {}
Student::Student() {}


// Setter methods
void Student::setID(const string& sid) { id = sid; }

void Student::setMarks(int smarks) {
    marks = smarks;
    grade = determine_grade(marks);
}

// Getter methods
string Student::getID() { return id; }
int Student::getMarks() { return marks; }
char Student::getGrade() { return grade; }

// Static method
char Student::determine_grade(int smarks) {
    if (smarks >= 80) return 'A';
    else if (smarks >= 65) return 'B';
    else if (smarks >= 50) return 'C';
    else return 'D';
}
