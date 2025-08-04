#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

const int MAX_SIZE = 10;

char determine_grade(int smarks);
void discard_line(ifstream &in);
void print_students_records(string sid[], int smarks[], char sgrades[], int size);
int total_failed_students(int smarks[], int size);

int main()
{
    string id[MAX_SIZE];
    int marks[MAX_SIZE];
    char grade[MAX_SIZE];
    int total_records;
    int choice;
    char response;

    ifstream input;

    cout<<"This program determines the grades of students."<<endl;

    cout<<"Program menu:"<<endl
        <<"(1) Read data from file"<<endl
        <<"(2) Read data from standard input"<<endl;
    cout<<"Enter the number of your choice: ";
    cin>>choice;

    cout<<endl;

    if (choice == 1){
        input.open("students2.txt",ios::in);

        if (input.fail()){
            cerr<<"File not found!"<<endl;
            system("PAUSE");
            exit(1);
        }

        discard_line(input);

        total_records = 0;
        while(!input.eof())
        {    
             input>>id[total_records]>>marks[total_records];
             cout<<"id: "<<id[total_records]<<", marks: "<<marks[total_records]<<endl;
             input>>ws;
    
             total_records++;
        }
    }
    else if (choice ==2){
        total_records = 0;
        do{
            cout<<"Enter student ID: ";
            cin>>id[total_records];

            cout<<"Enter marks gained: ";
            cin>>marks[total_records];

            cout<<"\nPress y or Y to enter another record.";
            cin>>response;
            cout<<endl;
            total_records++;
        }while((response == 'y' || response == 'Y') && (total_records < MAX_SIZE));
    }
    else{
        cout<<"ERROR! incorrect choice"<<endl;
        system("PAUSE");
        exit(1);
    }

    for (int i = 0; i < total_records; i++){
            grade[i] = determine_grade(marks[i]);
    }

    //Testing whether data have been read correctly or not.
    cout<<"\n\nData fed into the system:"<<endl<<endl;
    for (int i = 0; i < total_records; i++){
        cout<<"id: "<<id[i]<<", marks: "<<marks[i]<<endl;
    }

    input.close();

    print_students_records (id, marks, grade, total_records );

    cout<<"\n\nTotal students failed the course are: "
        <<total_failed_students(marks, total_records)<<endl;

    system("PAUSE");
    return 0;
}

void print_students_records(string sid[], int smarks[], char sgrades[],int size){
    cout<<"\n\nstudents records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<sid[i]<<", marks: "<<smarks[i]<<", grade: "<<sgrades[i]<<endl;
    }
}

int total_failed_students(int smarks[], int size){
    int failures;
    failures = 0;

    for (int i = 0; i < size; i++){
        if (smarks[i] < 50)
            failures++;
    }

    return failures;
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
