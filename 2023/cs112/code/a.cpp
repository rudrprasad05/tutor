#include <iostream>

using namespace std;

class Node{
    public: 
    Node *left;
    Node *right;
    int data;
    Node(int d) : data(d){};
};

void preOrder(Node *root){
    if(root == NULL) return;
    else{
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root){
    if(root == NULL) return;
    else{
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node *root){
    if(root == NULL) return;
    else{
        postOrder(root->left);
        postOrder(root->right);

        cout << root->data << " ";
    }
}

int max(Node *root){
    if (root == NULL) return INT_MIN;
    else{
        int l = max(root->left);
        int r = max(root->right);

        int current = root->data;

        if(l > current) current = l;
        if(r > current) current = r;

        return current;
    }
}

int height(Node *root){
    if(root == NULL) return 0;
    else{
        int l = height(root->left);
        int r = height(root->right);

        if(l > r) return 1 + l;
        else return 1 + r;
    }
}

int main(){
    Node *root = new Node(0);
    Node *a = new Node(1);
    Node *b = new Node(10);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    Node *h = new Node(9);


    root->left = a;
    root->right = b;

    a->left = c;

    b->right = d;
    b->left = e;

    c->right = f;

    e->right = g;
    g->right = h;

            //      root0
            //      /  \
            //     a1    b2
            //  /       /  \
            // c3       e5    d4
            //  \       \
            //    f6      g7

    preOrder(root);
    // 0 1 3 6 2 5 7 4
    cout << endl;
    
    inOrder(root);
    // 3 6 1 0 5 7 2 4
    cout << endl;

    postOrder(root);
    // 6 3 1 7 5 4 2 0
    cout << endl;

    cout << max(root) << endl;

    cout << height(root) << endl;


}