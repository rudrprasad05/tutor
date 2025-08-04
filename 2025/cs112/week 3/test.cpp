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
    ifstream file;
    string id[MAX_SIZE];
    int assignments[MAX_SIZE][5];
    int mst[MAX_SIZE];
    int finals[MAX_SIZE];
    int count = 0;

    file.open("students2.txt");

    if(file.fail()){

    }

    discard_line(file);

    while(!file.eof()){
        file >> id[count];

        for(int i = 0; i < 5; i++){
            file >> assignments[count][i];
        }
        file >> mst[count];
        file >> finals[count];
        file >> ws;
        count++;
    }

    for(int i = 0; i < count; i++){
        cout << id[i] << " ";
    }

}


void discard_line(ifstream &in)
{
    char c;

    do
   	    in.get(c);
    while (c!='\n');
}

void print_students_records(string sid[], int smarks[], char sgrades[],int size){
    cout<<"\n\nstudents records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<sid[i]<<", marks: "<<smarks[i]<<", grade: "<<sgrades[i]<<endl;
    }
}