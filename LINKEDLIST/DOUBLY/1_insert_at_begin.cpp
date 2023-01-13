#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = next = NULL;
    }
};

Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    return temp;
}
void printLL(Node *head)
{
    Node *curr = head;
    while (curr->next != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(10);
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 30);
    printLL(head);
    return 0;
}