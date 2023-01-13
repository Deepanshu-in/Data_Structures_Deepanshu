#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *insertAthead(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

int main()
{
    Node *head = NULL;
    head = insertAthead(head, 30);
    head = insertAthead(head, 20);
    head = insertAthead(head, 10);
    printLL(head);

    return 0;
}