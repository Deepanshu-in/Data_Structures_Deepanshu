#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(5);
    root->right->left = new Node(60);
    int c = height(root);
    cout << c;
    return 0;
}