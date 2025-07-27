#include <iostream>

using namespace std;

int add(int num){
    if(num == 0) return 0;
    else{
        return num + add(num-1);
    }
}

int main() {
    cout << add(5);
}




