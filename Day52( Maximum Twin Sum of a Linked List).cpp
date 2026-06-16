#include <iostream>
#include <vector>

// Maximum Twin Sum of a Linked List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode *head)
{
    stack<int> st;
    ListNode *curr = head;

    while (curr)
    {
        st.push(curr->val);
        curr = curr->next;
    }

    curr = head;
    int count = 1;
    int N = st.size();
    int result = 0;

    while (count <= N / 2)
    {
        result = max(result, curr->val + st.top());
        curr = curr->next;
        st.pop();
        count++;
    }

    return result;
}
