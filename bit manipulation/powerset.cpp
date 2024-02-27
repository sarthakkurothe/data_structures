/*
Power Set

https://www.geeksforgeeks.org/problems/power-set4302/1

Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

Example 1:

Input :
s = "abc"
Output:
a ab abc ac b bc c
Explanation :
There are a total 7 number of subsequences possible
for the given string, and they are mentioned above
in lexicographically sorted order.
Example 2:

Input:
s = "aa"
Output:
a a aa
Explanation :
There are a total 3 number of subsequences possible
for the given string, and they are mentioned above
in lexicographically sorted order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically-sorted order.
*/

class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> ans;
        int n = s.size();

        for (int i = 1; i < (1 << n); i++)
        {
            string str = "";
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    str += s[j];
                }
            }
            ans.push_back(str);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};