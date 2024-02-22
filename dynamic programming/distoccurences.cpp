/* Distinct occurrences

https://www.geeksforgeeks.org/problems/distinct-occurrences/1

Given two strings s and t of length n and m respectively. Find the count of distinct occurrences of t in s as a sub-sequence modulo 109 + 7.

Example 1:

Input:
s = "banana" , t = "ban"
Output:
3
Explanation:
There are 3 sub-sequences:[ban], [ba n], [b an].
Example 2:

Input:
s = "geeksforgeeks" , t = "ge"
Output:
6
Explanation:
There are 6 sub-sequences:[ge], [ge], [g e], [g e] [g e] and [g e].

 */

class Solution
{
public:
    int subsequenceCount(string s, string t)
    {
        const int mod = 1000000007;
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (t[j - 1] == s[i - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};