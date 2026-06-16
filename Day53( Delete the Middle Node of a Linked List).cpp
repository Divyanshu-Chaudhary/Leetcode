#include <iostream>
#include <vector>

// Delete the Middle Node of a Linked List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head)
{
    if (!head || !head->next)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head->next->next;

    while (fast && fast->next)
    {
        slow = slow->next;

        fast = fast->next->next;
    }

    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete (toDelete);

    return head;
}
