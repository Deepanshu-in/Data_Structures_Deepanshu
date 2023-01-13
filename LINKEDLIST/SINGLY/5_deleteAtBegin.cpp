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
Node *deleteAthead(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete (head);
        return temp;
    }
}

Node *insert(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void printLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    cout << "Before delete :- ";
    printLL(head);
    head = deleteAthead(head);
    cout << "After delete :- ";
    printLL(head);

    return 0;
}