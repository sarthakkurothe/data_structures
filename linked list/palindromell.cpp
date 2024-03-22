/*234. Palindrome Linked List

https://leetcode.com/problems/palindrome-linked-list/?envType=daily-question&envId=2024-03-22

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.



Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false


Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9


Follow up: Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        stack<int> s;
        while (temp != NULL)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (!s.empty())
        {
            if (s.top() != temp->val)
                return false;

            temp = temp->next;
            s.pop();
        }
        return true;
    }
};