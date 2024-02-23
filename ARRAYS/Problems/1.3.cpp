#include <iostream>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(NULL), prev(NULL) {}
};

// Function to reverse a doubly linked list
Node* reverseDLL(Node* head) {
    Node* temp = head;

    // Check if the list is empty
    if (temp == NULL) {
        return NULL;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Swap the next and prev pointers for each node
    while (temp != NULL) {
        Node* nexP = temp->next;
        temp->next = temp->prev;
        temp->prev = nexP;
        temp = temp->next;
    }

    // Update the head to the new start of the reversed list
    head = temp;

    return head;
}

// Function to print the elements of a doubly linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a doubly linked list with values 1, 2, 3, 4, 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    // Print original list
    cout << "Original List: ";
    printList(head);

    // Reverse the list
    head = reverseDLL(head);

    // Print reversed list
    cout << "Reversed List: ";
    printList(head);

    return 0;
}
