/*143. Reorder List

https://leetcode.com/problems/reorder-list/

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if ((!head) || (!head->next))
            return;
        ListNode *runner = head;
        stack<ListNode *> st;
        while (runner)
        {
            st.push(runner);
            runner = runner->next;
        }
        int size = st.size();
        runner = head;
        for (int i = 0; i < size / 2; i++)
        {
            st.top()->next = runner->next;
            runner->next = st.top();
            runner = runner->next->next;
            st.pop();
        }
        runner->next = NULL;
    }
};