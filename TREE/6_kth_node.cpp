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
void knode(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << " ";
    else
    {
        knode(root->left, k - 1);
        knode(root->right, k - 1);
    }
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(5);
    root->right->left = new Node(60);
    knode(root, 2);
    return 0;
}