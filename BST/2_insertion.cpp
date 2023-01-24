#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node* insert(Node* root,int x){
    if(root==NULL)
    return new Node(x);
    else if(root->key>x)
    root->left=insert(root->left,x);
    else if(root->key<x);
    root->right=insert(root->right,x);
    return root;
}
int main()
{

    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    insert(root,60);
}