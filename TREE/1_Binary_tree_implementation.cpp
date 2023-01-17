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

int main()
{
    Node *root = new Node(20);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(5);

    return 0;
}