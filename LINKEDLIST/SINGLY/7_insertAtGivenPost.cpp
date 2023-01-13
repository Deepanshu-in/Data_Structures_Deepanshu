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
Node *insert(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *insertAtPos(Node *head, int pos, int x)
{
    Node *temp = new Node(x);
    if (pos == 1)
    {
        temp->next == head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i < pos - 2 && curr != NULL; i++)
        curr = curr->next;
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
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
    printLL(head);
    head = insertAtPos(head, 2, 25);
    printLL(head);

    return 0;
}