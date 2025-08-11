#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

float sum_of_double(float *dbl_array, int size);

int main()
{
    const int MAX_SIZE = 10;

    float a;
    float b;
    float sum;
    float double_array[MAX_SIZE];

    char response;
    char read_file;

    int counter;
    int total_elements;

    ifstream in;

    sum = 0;
    counter = 0;

    in.open("numbers.txt",ios::in);

    if(!in){
        cerr<<"File could not be oopened."<<endl;
        system("PAUSE");
        exit(1);
    }
    else
        cout<<"Data read from file numbers.txt"<<endl;

    counter = 0;
    while(in>>a){
        double_array[counter] = 2*a;
        counter++;
        total_elements = counter;
    }

    cout<<"The double of values read are: "<<endl;
    for (int i = 0; i<total_elements; i++)
        cout<<double_array[i]<<" ";

    cout<<"\n\nThe total number read was: "<<total_elements<<endl;

    cout<<"\n\nThe sum of double of input values are: "<<sum_of_double(double_array,total_elements)<<endl;


    system("PAUSE");
    return 0;
}

float sum_of_double(float *dbl_array, int size){
    float sum = 0;

    for (int i = 0; i < size; i++)
        sum += *(dbl_array + i);  // Using pointer arithmetic

    return sum;
}
