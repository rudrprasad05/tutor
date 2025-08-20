#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string>

const int MAX_SIZE = 10;

class student{
    public:
        student();
        ~student();
        void set_id(string);
        void set_marks(int);
        void set_grade(char);
        string get_id();
        int get_marks();
        char get_grade();

    private:
        string id;
        int marks;
        char grade;
};

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

char determine_grade(int smarks);
void discard_line(ifstream &in);
void print_students_records(student s_info[], int size);



int main()
{
    student student_info[MAX_SIZE];

    int total_records;
    int choice;
    char response;

    ifstream input;

    cout<<"This program determines the grades of students."<<endl;

	input.open("F:\\CS112\\Teaching_Materials\\week5\\Tutorials\\students.txt",ios::in);

	if(!input){
		cerr<<"File could not be opened"<<endl;
		exit(1);
	}

	discard_line(input);

	total_records = 0;

    string temp_id;
    int temp_marks;

	while(input>>temp_id>>temp_marks){
        student_info[total_records].set_id(temp_id);
        student_info[total_records].set_marks(temp_marks);

        total_records++;
	}

    for (int i = 0; i < total_records; i++){
        student_info[i].set_grade(determine_grade(student_info[i].get_marks()));
    }

    input.close();

    print_students_records (student_info, total_records );

    system("PAUSE");
    return 0;
}

void print_students_records(student s_info[],int size){
    cout<<"\n\nstudents' records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<s_info[i].get_id()
            <<", marks: "<<s_info[i].get_marks()
            <<", grade: "<<s_info[i].get_grade()<<endl;
    }
}

char determine_grade(int smarks){
     char sgrade;

     if (smarks >= 80)
        sgrade = 'A';
     else if(smarks >= 65)
        sgrade = 'B';
     else if(smarks >= 50)
        sgrade = 'C';
     else
        sgrade = 'D';

     return sgrade;
}

void discard_line(ifstream &in)
{
    char c;

    do
   	    in.get(c);
    while (c!='\n');
}
