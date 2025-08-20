#include <iostream>
#include <fstream>
#include <cstdlib>   // for exit()
#include <string>

const int MAX_SIZE = 10;

char determine_grade(int smarks);
void discard_line(std::ifstream &in);
void print_students_records(const std::string sid[], const int smarks[], const char sgrades[], int size);

int main()
{
    std::string id[MAX_SIZE];
    int marks[MAX_SIZE];
    char grade[MAX_SIZE];
    int total_records = 0;

    std::ifstream input("E:\\students.txt", std::ios::in);

    if(!input){
        std::cerr << "File could not be opened" << std::endl;
        exit(1);
    }

    discard_line(input); // skip header line

    while(total_records < MAX_SIZE && input >> id[total_records] >> marks[total_records]){
        total_records++;
    }

    for (int i = 0; i < total_records; i++){
        grade[i] = determine_grade(marks[i]);
    }

    input.close();

    print_students_records(id, marks, grade, total_records);

    system("PAUSE");
    return 0;
}

void print_students_records(const std::string sid[], const int smarks[], const char sgrades[], int size){
    std::cout << "\n\nStudents' Records\n\n";
    for (int i = 0; i < size; i++){
        std::cout << "ID: " << sid[i] << ", Marks: " << smarks[i] << ", Grade: " << sgrades[i] << std::endl;
    }
}

char determine_grade(int smarks){
    if (smarks >= 80)
        return 'A';
    else if(smarks >= 65)
        return 'B';
    else if(smarks >= 50)
        return 'C';
    else
        return 'D';
}

void discard_line(std::ifstream &in)
{
    char c;
    do
        in.get(c);
    while (in && c != '\n');
}
