#include <iostream>

using namespace std;

class Node{
    public:
    Node *next;
    int data;

    

};

void go(Node *head){
    if(head == NULL){
        return;
    }
    else{
        cout << head->data << " ";
        go(head->next);
    }
}

void append(Node *head, int data){
    Node *current = head;
    Node *newNode = new Node();
    newNode->data = data;

    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insert(Node *prev, Node *next, int data){
    Node *current = prev;
    Node *temp = next;

    Node *newNode = new Node();
    newNode->data = data;

    current->next = newNode;
    newNode->next = temp;
}

void pop(Node *head){
    Node *current = head;
    while(current->next->next != NULL){
        current = current->next;
    }

    Node *temp = current->next;
    current->next = nullptr;
    delete temp;

}

void remove(Node *prev, Node *next, Node*head){
    Node *current = prev;
    Node *nextNode = next;

    Node *temp = prev->next;
    current->next = next;

    delete temp;
}

int main(){
    Node *head = NULL;
    Node *a = new Node;
    head = a;
    a->data= 1;
    
    Node *b = new Node;
    b->data = 2;

    Node *c = new Node;
    c->data = 3;

    Node *d = new Node;
    d->data = 4;

    Node *e = new Node;
    e->data = 5;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    append(head, 10);
    insert(a,b,20);


    // Node *current = NULL;
    // for(current = head; current != NULL; current = current->next){
    //     cout << current->data << " ";
    // }
    go(head);
    cout << endl;
    pop(head);
    go(head);
    cout << endl;
    remove(c,e,head);
    cout << endl;
    go(head);

}