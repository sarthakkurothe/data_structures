/* Largest Number formed from an Array

 https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

 Given an array of strings arr[] of length n representing non-negative integers, arrange them in a manner, such that, after concatanating them in order, it results in the largest possible number. Since the result may be very large, return it as a string.

Example 1:

Input:
n = 5
arr[] =  {"3", "30", "34", "5", "9"}
Output: "9534330"
Explanation:
Given numbers are  {"3", "30", "34", "5", "9"},
the arrangement "9534330" gives the largest value.
Example 2:

Input:
n = 4
arr[] =  {"54", "546", "548", "60"}
Output: "6054854654"
Explanation:
Given numbers are {"54", "546", "548", "60"}, the
arrangement "6054854654" gives the largest value.
Your Task:
You don't need to read input or print anything. Your task is to complete the function printLargest() which takes the array of strings arr[] as a parameter and returns a string denoting the answer.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
    static bool cmp(string &s1, string &s2)
    {
        return s1 + s2 > s2 + s1;
    }

public:
    string printLargest(int n, vector<string> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        string ans = "";
        for (int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
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
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends