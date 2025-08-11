#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    float a;
    float b;
    float sum;

    cout<<"Enter first number: ";
    cin>>a;

    cout<<"Enter second number: ";
    cin>>b;

    sum = a + b;

    cout<<"The sum of two numbers is: "<<sum<<endl;

    /////////

    cout << "Address: " << &sum << endl;

    system("PAUSE");
    return 0;
}
