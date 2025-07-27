#include <iostream>
#include <math.h>

using namespace std;

class person{
    private:
        string name;
    public: 
        string getName();
        friend void sayHello();
};

string person::getName(){
    cout << this->name;
}

void sayHello(){

}

int main(){
    int a = 5;
    int &b = a;
    int *ptr = &a;
    b = 10;

    *ptr += 1;
    cout << &b << ',' << &a;
}