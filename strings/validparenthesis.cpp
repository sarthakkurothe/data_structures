/*678. Valid Parenthesis String

https://leetcode.com/problems/valid-parenthesis-string/?envType=daily-question&envId=2024-04-07

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

*/

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0;
        int high = 0;
        for (char c : s)
        {
            low += (c == '(') ? 1 : -1;
            high += (c != ')') ? 1 : -1;

            if (high < 0)
                break;
            low = max(low, 0);
        }
        return low == 0;
    }
};
