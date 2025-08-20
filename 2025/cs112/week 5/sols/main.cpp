#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Student.h"

using namespace std;

const int MAX_SIZE = 10;

void discard_line(ifstream &in);
void print_students_records(Student s[], int size);

int main() {
    Student students[MAX_SIZE];
    int total_records = 0;

    ifstream input("students.txt", ios::in);
    if (!input) {
        cerr << "File could not be opened" << endl;
        system("PAUSE");
        exit(1);
    }

    cout << "This program determines the grades of students." << endl;

    discard_line(input); // skip header

    string sid;
    int smarks;
    while (total_records < MAX_SIZE && input >> sid >> smarks) {
        students[total_records] = Student(sid, smarks);
        total_records++;
    }

    input.close();

    print_students_records(students, total_records);

    system("PAUSE");
    return 0;
}

// Print function
void print_students_records(Student s[], int size) {
    cout << "\n\nStudents' Records\n\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << s[i].getID()
             << ", Marks: " << s[i].getMarks()
             << ", Grade: " << s[i].getGrade() << endl;
    }
}

// Skip header line
void discard_line(ifstream &in) {
    char c;
    do {
        in.get(c);
    } while (in && c != '\n');
}
