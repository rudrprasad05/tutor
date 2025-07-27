#include <iostream>
#include <math.h>

using namespace std;

class Node{
    public: 
        int data;
        Node* next;
};

int main(){

    Node *n = new Node;

    for(int i = 0; i < 10; i++){
        n->next = new Node;
        n->next->data = i;
        n = n->next;
    }

    for(int i = 0; i < 10; i++){
        cout << n->data << " ";
        n = n->next;
    }
}