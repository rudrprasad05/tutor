#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
};



void insertStart(Node **head){
    Node *newNode = new Node();
    newNode->data = 100;
    newNode->next = *head;
    *head = newNode;


}

void insertEnd(Node **head){
    Node *newNode = new Node();
    newNode->data = 45;
    newNode->next =NULL;

    if(*head == NULL){
        return;
    }
    Node *last = *head;
    while(last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
}

void deleteNode(Node **head){

}

int main(){

    // Node *a = new Node();
    // Node *b = new Node();
    // Node *c = new Node();

    // Node *head = a;

    // head->next = b;
    // head->next->next = c;
    // head->next->next->next = NULL;

    // head->data = 1;
    // head->next->data = 2;
    // head->next->next->data = 3;
    

    // Node *temp = head;

    // while(temp != NULL){
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    

    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();

    Node *head = c;

    a->prev = NULL;
    a->next = b;
    a->data = 1;

    b->prev = a;
    b->next = c;
    b->data = 2;


    c->prev = b;
    c->next = NULL;
    c->data = 3;


    Node *temp = NULL;

    for(temp = c; temp != NULL; temp = temp->prev){
        cout << temp->data << " ";
    }


    


}
