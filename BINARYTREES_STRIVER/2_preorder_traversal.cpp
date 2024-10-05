#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->right = new Node(7);
    preorder(root);
    return 0;
}