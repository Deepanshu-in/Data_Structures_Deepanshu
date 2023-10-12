
//In a circular linked list,find the number of even & odd numbers in it.find the complexity

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


void countEvenOdd(Node * head) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        int evenCount = 0;
        int oddCount = 0;
        Node* current = head;
        do {
            if (current->data % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
            current = current->next;
        } while (current != head);

        cout << "Number of even numbers: " << evenCount <<endl;
        cout << "Number of odd numbers: " << oddCount <<endl;
}


int main()
{
    Node *head = new Node(7);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    countEvenOdd(head);
    return 0;
}
