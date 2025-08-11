#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

const int MAX_SIZE = 10;
const int MAX_ASSIGNMENTS = 5;

struct Student {
    string id;
    int assignment_marks[MAX_ASSIGNMENTS];
    int mst_mark;
    int final_mark;
    int total_mark;
    char grade;
};

char determine_grade(int smarks);
void discard_line(ifstream &in);
void print_students_records(Student s[], int size);
void print_students_coursework(Student s[], int size);
int total_failed_students(Student s[], int size);

int main()
{
    Student s[MAX_SIZE];
    int total_records = 0;
    int choice;
    char response;

    ifstream input;

    cout << "This program determines the grades of students." << endl;

    cout << "Program menu:" << endl
         << "(1) Read data from file" << endl
         << "(2) Read data from standard input" << endl;
    cout << "Enter the number of your choice: ";
    cin >> choice;

    cout << endl;

    if (choice == 1){
        input.open("students2.txt", ios::in);

        if (input.fail()){
            cerr << "File not found!" << endl;
            system("PAUSE");
            exit(1);
        }

        discard_line(input);

        while(!input.eof() && total_records < MAX_SIZE)
        {    
            input >> s[total_records].id;
            for(int i = 0; i < MAX_ASSIGNMENTS; i++){
                input >> s[total_records].assignment_marks[i];
            }
            input >> s[total_records].mst_mark;
            input >> s[total_records].final_mark;

            cout << "id: " << s[total_records].id 
                 << ", mst: " << s[total_records].mst_mark 
                 << ", final: " << s[total_records].final_mark << endl;

            input >> ws;

            total_records++;
        }

        input.close();
    }
    else if (choice == 2){
        do{
            cout << "Enter student ID: ";
            cin >> s[total_records].id;

            cout << "Enter MST mark: ";
            cin >> s[total_records].mst_mark;

            cout << "Enter Final mark: ";
            cin >> s[total_records].final_mark;

            // Optionally, read assignments if needed here or set them to zero
            for(int i = 0; i < MAX_ASSIGNMENTS; i++){
                s[total_records].assignment_marks[i] = 0; // or ask user
            }

            cout << "\nPress y or Y to enter another record: ";
            cin >> response;
            cout << endl;

            total_records++;
        } while ((response == 'y' || response == 'Y') && (total_records < MAX_SIZE));
    }
    else{
        cout << "ERROR! incorrect choice" << endl;
        system("PAUSE");
        exit(1);
    }

    // Calculate total marks and grades
    for (int i = 0; i < total_records; i++){
        s[i].total_mark = s[i].mst_mark + s[i].final_mark;
        s[i].grade = determine_grade(s[i].total_mark);
    }

    // Testing data output
    cout << "\n\nData fed into the system:" << endl << endl;
    for (int i = 0; i < total_records; i++){
        cout << "id: " << s[i].id << ", MST mark: " << s[i].mst_mark << endl;
    }

    print_students_records(s, total_records);
    print_students_coursework(s, total_records);

    cout << "\n\nTotal students failed the course are: "
         << total_failed_students(s, total_records) << endl;

    system("PAUSE");
    return 0;
}

void print_students_coursework(Student s[], int size) {
    cout << "\n\nStudents coursework" << endl << endl;
    for (int i = 0; i < size; i++){
        cout << "id: " << s[i].id << ", course work: " << s[i].mst_mark << endl;
    }
}

void print_students_records(Student s[], int size){
    cout << "\n\nStudents records" << endl << endl;
    for (int i = 0; i < size; i++){
        cout << "id: " << s[i].id;
        cout << ", assignments: ";
        for(int j = 0; j < MAX_ASSIGNMENTS; j++){
            cout << s[i].assignment_marks[j] << " | ";
        }
        cout << ", grade: " << s[i].grade << endl;
    }
}

int total_failed_students(Student s[], int size){
    int failures = 0;

    for (int i = 0; i < size; i++){
        if (s[i].mst_mark < 50)  // Assuming failure based on MST marks as in your original
            failures++;
    }

    return failures;
}

char determine_grade(int smarks){
    if (smarks >= 80)
        return 'A';
    else if (smarks >= 65)
        return 'B';
    else if (smarks >= 50)
        return 'C';
    else
        return 'D';
}

void discard_line(ifstream &in)
{
    char c;
    do
        in.get(c);
    while (c != '\n');
}
