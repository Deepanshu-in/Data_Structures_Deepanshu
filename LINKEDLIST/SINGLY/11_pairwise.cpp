#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL)
    {
        ListNode *first = prev->next;
        ListNode *second = prev->next->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy.next;
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{

    ListNode *head = new ListNode(6);
    head->next = new ListNode(7);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(9);
    head->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next = new ListNode(11);
    head->next->next->next->next->next->next = new ListNode(12);
    head->next->next->next->next->next->next->next = new ListNode(13);
    head->next->next->next->next->next->next->next->next = new ListNode(14);

    std::cout << "Original list: ";
    printList(head);

    head = swapPairs(head);

    std::cout << "Swapped list: ";
    printList(head);

    while (head != NULL)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}