/*Check if a number is divisible by 8

https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1

Given a string representation of a decimal number s, check whether it is divisible by 8.

Example 1:

Input:
s = "16"
Output:
1
Explanation:
The given number is divisible by 8,
so the driver code prints 1 as the output.
Example 2:

Input:
s = "54141111648421214584416464555"
Output:
-1
Explanation:
Given Number is not divisible by 8,
so the driver code prints -1 as the output.
Your Task:
You don't need to read input or print anything.Your task is to complete the function DivisibleByEight() which takes a string s as the input and returns 1 if the number is divisible by 8, else it returns -1.
*/

class Solution
{
public:
    int DivisibleByEight(string s)
    {
        int n = s.size();
        if (n <= 3)
        {
            int num = stoi(s);
            if (num % 8 == 0)
                return 1;
            else
                return -1;
        }

        string str = s.substr(n - 3);
        int num = stoi(str);

        if (num % 8 == 0)
            return 1;
        return -1;
    }
};