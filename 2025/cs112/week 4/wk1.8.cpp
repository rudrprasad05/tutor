#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    const int MAX_SIZE = 10;

    float a;
    float b;
    float sum;
    float *ptr_double_array; //////
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
        cerr<<"File could not be pened."<<endl;
        system("PAUSE");
        exit(1);
    }
    else
        cout<<"Data read from file numbers.txt"<<endl;


    ptr_double_array = double_array; //////////

    counter = 0;
    while(in>>a){
        ///////////////////

        // double_array[counter] = 2*a;
        *(ptr_double_array + counter) = 2 * a; 
        counter++;
        
    }
    total_elements = counter;
    
    cout << "The double of values read are: " << endl;
    for (int i = 0; i < total_elements; i++)
    cout << *(ptr_double_array + i) << " ";
    
    cout << "\n\nThe total number read was: " << total_elements << endl;
    
    system("PAUSE");
    return 0;
    /////////////////////
}


