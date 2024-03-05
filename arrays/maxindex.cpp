/*
Maximum Index

https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1

Given an array a of n positive integers. The task is to find the maximum of j - i subjected to the constraint of a[i] < a[j] and i < j.

Example 1:

Input:
n = 2
a[] = {1, 10}
Output:
1
Explanation:
a[0] < a[1] so (j-i) is 1-0 = 1.
Example 2:

Input:
n = 9
a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array a[1] < a[7] satisfying the required condition(a[i] < a[j]) thus giving the maximum difference of j - i which is 6(7-1).
Your Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxIndexDiff(int a[], int n)
    {
        int ans = 0;
        int id = 0;

        for (int i = 0; i < n; i++)
        {
            if (i + ans >= n)
            {
                break;
            }
            for (int j = n - 1; j > max(i, id); j--)
            {
                if (a[i] <= a[j])
                {
                    ans = max(ans, j - i);
                    id = max(id, j);
                    break;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}
// } Driver Code Ends