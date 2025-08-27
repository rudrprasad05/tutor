#include "student.h"

student::student(){;}

student::~student(){;}

void student::set_id(string id){
    this->id = id;
}
void student::set_marks(int marks){
    this->marks = marks;
}
void student::set_grade(char grade){
    this->grade = grade;
}

string student::get_id(){
    return id;
}
int student::get_marks(){
    return marks;
}
char student::get_grade(){
    return grade;
}
