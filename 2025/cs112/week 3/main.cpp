#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

const int MAX_SIZE = 10;
const int MAX_ASSIGNMENTS = 5;

char determine_grade(int smarks);
void discard_line(ifstream &in);
void print_students_records(string sid[], int assignment_marks[][MAX_ASSIGNMENTS], char sgrades[],int size);
void print_students_coursework(string id[], int coursework[], int size);
int total_failed_students(int smarks[], int size);

int main()
{
    string id[MAX_SIZE];
    int assignment_marks[MAX_SIZE][MAX_ASSIGNMENTS];
	int mst_marks[MAX_SIZE];
	int final_marks[MAX_SIZE];
	int total_marks[MAX_SIZE];
	
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
	         input >> id[total_records]; // >> put marks into final;
	         for(int i = 0; i < MAX_ASSIGNMENTS; i++){
	         	input >> assignment_marks[total_records][i];
			 }
			 input >> mst_marks[total_records];
			 input >> final_marks[total_records];
			 
	         cout<<"id: "<<id[total_records]<<", mst : "<<mst_marks[total_records] << ", final : "<<final_marks[total_records]<<endl;
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
            cin>>mst_marks[total_records];

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

    for(int i = 0; i < total_records; i++){
    	total_marks[i] = mst_marks[i] + final_marks[i];
	}
	
	for (int i = 0; i < total_records; i++){
            grade[i] = determine_grade(total_marks[i]);
    }

    //Testing whether data have been read correctly or not.
    cout<<"\n\nData fed into the system:"<<endl<<endl;
    for (int i = 0; i < total_records; i++){
        cout<<"id: "<<id[i]<<", marks: "<<mst_marks[i]<<endl;
    }

    input.close();

    print_students_records (id, assignment_marks, grade, total_records );
    print_students_coursework(id, mst_marks, total_records);

    cout<<"\n\nTotal students failed the course are: "
        <<total_failed_students(mst_marks, total_records)<<endl;

    system("PAUSE");
    return 0;
}

void print_students_coursework(string id[], int coursework[], int size) {
	cout<<"\n\nstudents course work"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<id[i]<<", course work: "<< coursework[i] <<endl;
    }
}

void print_students_records(string sid[], int assignment_marks[][MAX_ASSIGNMENTS], char sgrades[],int size){
    cout<<"\n\nstudents records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<sid[i]; 
        cout<<", assignment: "; 
        
        for(int j = 0; j < MAX_ASSIGNMENTS; j++){
        	cout << assignment_marks[i][j] << " | ";
		}
		
		cout <<", grade: "<<sgrades[i]<<endl;
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
