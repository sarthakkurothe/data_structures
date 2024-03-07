/*Longest repeating and non-overlapping substring

https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1

Given a string s of length n, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. Return the longest non-overlapping substring. Return "-1" if no such string exists.

Note: Multiple Answers are possible but you have to return the substring whose first occurrence is earlier.

For Example: "abhihiab", here both "ab" and "hi" are possible answers. But you will have to return "ab" because it's first occurrence appears before the first occurrence of "hi".

Example 1:

Input:
n = 9
s = "acdcdacdc"
Output:
"acdc"
Explanation:
The string "acdc" is the longest Substring of s which is repeating but not overlapping.
Example 2:

Input:
n = 7
s = "heheheh"
Output:
"heh"
Explanation:
The string "heh" is the longest Substring of s which is repeating but not overlapping.
Your Task:
You don't need to read input or print anything. Your task is to complete the function longestSubstring() which takes an Integer n and a string s as input and returns the answer.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestSubstring(string s, int n)
    {
        int i = 0;
        int j = 0;
        string ans = "-1";
        int sz = 0;
        while (i < n && j < n)
        {
            string str = s.substr(i, (j - i + 1));
            if (s.find(str, (j + 1)) != string::npos)
            {
                if (str.size() > sz)
                {
                    ans = str;
                    sz = str.size();
                }
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends