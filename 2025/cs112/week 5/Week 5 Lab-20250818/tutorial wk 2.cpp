#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

const int MAX_SIZE = 10;

char determine_grade(int smarks);
void discard_line(ifstream &in);
void print_students_records(string sid[], int smarks[], char sgrades[], int size);

int main(){
    string id[MAX_SIZE];
    int marks[MAX_SIZE];
    char grade[MAX_SIZE];
    int total_records;
    int choice;
    char response;

    ifstream input;
    cout<<"This program determines the grades of students."<<endl;

    input.open("students.txt",ios::in);

    if(!input){
		cerr<<"File could not be opened"<<endl;
		system("PAUSE");
		exit(1);
	}
    
    discard_line(input);

    total_records = 0;

    while(input>>id[total_records]>>marks[total_records]){
        total_records++;
    }

    for (int i = 0; i < total_records; i++){
        grade[i] = determine_grade(marks[i]);
    }

    input.close();

    print_students_records (id, marks, grade, total_records );
    
    system("PAUSE");
    return 0;  
}

void print_students_records(string sid[], int smarks[], char sgrades[],int size){
    cout<<"\n\nstudents' records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<sid[i]<<", marks: "<<smarks[i]<<", grade: "<<sgrades[i]<<endl;
    }
    cout<<endl;
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
