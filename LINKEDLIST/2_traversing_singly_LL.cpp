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

// iterative traversing
void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// recursive traversing
void rPrint(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    rPrint(head->next);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(45);

    // iterative
    printList(head);

    cout << endl;

    // recursive
    rPrint(head);

    return 0;
}