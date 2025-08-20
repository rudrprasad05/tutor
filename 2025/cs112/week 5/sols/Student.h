#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string id;
    int marks;
    char grade;

public:
    // Constructor & Destructor
    Student(string sid, int smarks);
    Student();

    ~Student();

    // Setter methods
    void setID(const string& sid);
    void setMarks(int smarks);

    // Getter methods
    string getID();
    int getMarks();
    char getGrade();

    // Static method to determine grade
    static char determine_grade(int smarks);
};

#endif
