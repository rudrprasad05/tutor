#include <iostream>

using namespace std;

class Node{
    public: 
        int data;
        Node *left; 
        Node *right;
};

int nodes(Node* root){
    if(root == NULL) return 0;
    else{
        return 1 + nodes(root->left) + nodes(root->right);
    }
}

int max(Node *root){
    if(root == NULL) return 0;
    else{
        int l = max(root->left);
        int r = max(root->right);

        int current = root->data;

        if(l > r) current = l;
        if(r > l) current = r;

        return current;
    }
}

int leaf(Node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->left == NULL) return 1;
    else{
        return leaf(root->left) + leaf(root->right);
    }
}


int sum(Node *root){
    if(root == NULL) return 0;
    else{
        return root->data + sum(root->left) + sum(root->right);
    }
}

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->left == NULL) return 1;

    else{
        int l = height(root->left);
        int r = height(root->right);

        if(l < r) return l + 1;
        else return r + 1;
    }
}

int main(){
    Node *root = new Node();
    root->data = 1;
    Node* a = new Node();
    a->data = 2;
    Node* b = new Node();
    b->data = 3;
    Node* c = new Node();
    c->data = 10;
    Node* d = new Node();
    d->data = 5;
    Node* e = new Node();
    e->data = 6;
    Node* f = new Node();
    f->data = 7;

    root->left = a;
    root->right = b;

    a->left = c;
    
    b->left = d;
    b->right = e;

    d->right = f;

    cout << max(root) << endl;
    cout << nodes(root) << endl;
    cout << leaf(root) << endl;
    cout << height(root) << endl;
    cout << sum(root) << endl;

    int *m = new int(5);
    cout << m << " " << *m << endl;


    //     root
    //     /   \
    //    a    b
    //    /   / \
    //   c   d  e
    //        \
    //         f

    int a1 = 5;
    int *b1 = &a1;
    int **c1 = &b1;

    cout << a1 << " " << *b1 << " " << **c1 << endl;

    a1 = 10;

    cout << a1 << " " << *b1 << " " << **c1 << endl;

    int z, x, y;
    x = y = 10;

    cout << x << y << endl;

}