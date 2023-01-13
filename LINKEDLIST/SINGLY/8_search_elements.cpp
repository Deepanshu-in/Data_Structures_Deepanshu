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

int searchPos(Node *head, int data)
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == data)
            return pos;
        else
        {
            pos++;
            curr = curr->next;
        }
    }
    return pos;
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
    int j = searchPos(head, 20);
    cout << "The position of 20 in LL is " << j << endl;
    return 0;
}