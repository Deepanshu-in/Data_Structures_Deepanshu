#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> preorderIterative(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res; // Return an empty vector instead of nothing

    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        res.push_back(curr->data);
        if (curr->right != NULL)
            s.push(curr->right);
        if (curr->left != NULL)
            s.push(curr->left);
    }
    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->right = new Node(7);

    vector<int> res = preorderIterative(root);

    for (int val : res)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
