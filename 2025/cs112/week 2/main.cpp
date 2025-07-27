#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to discard unneeded lines from input file
void discard_line(ifstream &in) {
    char c;
    do
        in.get(c);
    while (c != '\n');
}

// Function to determine grade based on marks
char determine_grade(int marks) {
    if (marks >= 80 && marks <= 100) {
        return 'A';
    }
    else if (marks >= 65 && marks <= 79) {
        return 'B';
    }
    else if (marks >= 50 && marks <= 64) {
        return 'C';
    }
    else if (marks >= 0 && marks <= 49) {
        return 'D';
    }
    return 'D'; // Default case
}

// Function to print all student records
void print_students_records(string student_ids[], int marks[], int num_students) {
    cout << "\n=== STUDENT RECORDS ===" << endl;
    cout << "ID\t\tMarks\tGrade" << endl;
    cout << "------------------------" << endl;
    
    for (int i = 0; i < num_students; i++) {
        char grade = determine_grade(marks[i]);
        cout << student_ids[i] << "\t" << marks[i] << "\t" << grade << endl;
    }
}

int main() {
    const int MAX_STUDENTS = 100;
    string student_ids[MAX_STUDENTS];
    int marks[MAX_STUDENTS];
    int num_students = 0;
    int failed_count = 0;
    
    // Option 1: Read from standard input
    cout << "Choose input method:" << endl;
    cout << "1. Enter data manually" << endl;
    cout << "2. Read from students.txt file" << endl;
    cout << "Enter choice (1 or 2): ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        // Manual input from standard input
        cout << "Enter number of students: ";
        cin >> num_students;
        
        cout << "Enter student data (ID and marks):" << endl;
        for (int i = 0; i < num_students; i++) {
            cout << "Student " << (i + 1) << " ID: ";
            cin >> student_ids[i];
            cout << "Student " << (i + 1) << " marks: ";
            cin >> marks[i];
        }
        
        // Print all data after entering
        cout << "\n=== DATA ENTERED ===" << endl;
        for (int i = 0; i < num_students; i++) {
            cout << "ID: " << student_ids[i] << ", Marks: " << marks[i] << endl;
        }
    }
    else if (choice == 2) {
        // Read from file
        ifstream input_file("students.txt");
        
        if (!input_file.is_open()) {
            cout << "Error: Cannot open students.txt file!" << endl;
            return 1;
        }
        
        // Discard the header line
        discard_line(input_file);
        
        // Read student data from file
        string id;
        int mark;
        while (input_file >> id >> mark && num_students < MAX_STUDENTS) {
            student_ids[num_students] = id;
            marks[num_students] = mark;
            num_students++;
        }
        
        input_file.close();
        
        // Print all data from file
        cout << "\n=== DATA FROM FILE ===" << endl;
        for (int i = 0; i < num_students; i++) {
            cout << "ID: " << student_ids[i] << ", Marks: " << marks[i] << endl;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    // Print student records with grades
    print_students_records(student_ids, marks, num_students);
    
    // Count failed students (marks < 50)
    for (int i = 0; i < num_students; i++) {
        if (marks[i] < 50) {
            failed_count++;
        }
    }
    
    cout << "\n=== STATISTICS ===" << endl;
    cout << "Total number of students: " << num_students << endl;
    cout << "Number of students who failed CS112: " << failed_count << endl;
    
    return 0;
}