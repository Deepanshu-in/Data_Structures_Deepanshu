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

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool checkPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *reversed = head;
    reversed = reverseList(slow);
    Node *mid = reversed;
    Node *h = head;
    while (h != reversed && mid != NULL)
    {
        if (h->data == mid->data)
        {
            h = h->next;
            mid = mid->next;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    if (checkPalindrome(head))
        cout << "Linkedlist is palindrome";
    else
        cout << "LinkedList is not palindrome";
    return 0;
}