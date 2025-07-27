#include <iostream>

using namespace std;


int bin(int low, int high, int key, int arr[]){
    if(low == high){
        if(arr[low] == key){
            return low;
        }
    }
    else{
        int mid = (high - low)/2;
        if(key == arr[mid]){
            return mid;
        }
        if(key < arr[mid]){
            return bin(low, mid-1, key, arr);
        }
        else{
            return bin(mid-1, high, key, arr);
        }
    }
}


int main(){

    char arr[][10] = {"hello", "hi", "world"};

    for(int i = 0; i < 3; i++){
        cout << arr[i];
    }
}