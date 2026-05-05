#include <iostream>
using namespace std;

ListNode *rotateRight(ListNode *head, int k)
{
    // 1. Edge cases
    if (!head || !head->next || k == 0)
        return head;

    // 2. Compute length and find the actual tail
    ListNode *tail = head;
    int n = 1;
    while (tail->next)
    {
        tail = tail->next;
        n++;
    }

    // 3. Make the list circular
    tail->next = head;

    // 4. Calculate steps to the new tail
    k %= n;
    int stepsToNewTail = n - k;

    // Find the node that will become the new tail
    ListNode *newTail = tail;
    while (stepsToNewTail--)
    {
        newTail = newTail->next;
    }

    // 5. Break the circle and set new head
    head = newTail->next;
    newTail->next = nullptr;

    return head;
}

int main()
{
    return 0;
}