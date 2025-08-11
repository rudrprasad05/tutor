#include <iostream>
#include <stdlib.h>
using namespace std;

float do_sum(float a, float b);
float do_sum_by_ref(float a, float b, float *sum);

int main()
{
    float a;
    float b;
    float sum;

    cout<<"Enter first number: ";
    cin>>a;

    cout<<"Enter second number: ";
    cin>>b;

    do_sum_by_ref(a, b, &sum);

    cout<<"The sum of two numbers is: "<<sum<<endl;

    if (sum > 0)
        cout<<"sum is positive"<<endl;
    else if(sum < 0)
        cout<<"sum is negative"<<endl;
	else
		cout<<"sum is zero"<<endl;

    system("PAUSE");
    return 0;
}

float do_sum(float a, float b){
    return (a+b);
}

float do_sum_by_ref(float a, float b, float *sum){
    *sum = a + b;
    return *sum;
}
