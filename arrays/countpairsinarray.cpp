/*Count Pairs in an Array

 https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1


Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

Note: 0-based Indexing is followed.

Example 1:

Input :
n = 4
arr[] = {8, 4, 2, 1}
Output :
2
Explanation:
If we see the array after operations
[0*8, 1*4, 2*2, 3*1] => [0, 4, 4, 3]
Pairs which hold the condition i*arr[i] > j*arr[j] are (4,1) and (2,1), so in total 2 pairs are available.
Example 2:

Input :
n = 7
arr[] = {5, 0, 10, 2, 4, 1, 6}
Output:
5
Explanation :
Pairs which hold the condition i*arr[i] > j*arr[j] are (10,2), (10,4), (10,1), (2,1) and (4,1), so in total 5 pairs are there.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs() which takes the array arr[] and its size n as inputs and returns the required result.

Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n*log(n))

Constraints:
1 ≤ n ≤ 104
0 ≤ arr[i] ≤ 104

 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int merge(vector<int> &a, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1, c = 0;

        while (left <= mid && right <= high)
        {
            if (a[left] <= a[right])
            {
                temp.push_back(a[left]);
                left++;
            }
            else
            {
                c += (mid - left + 1);
                temp.push_back(a[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(a[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(a[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
            a[i] = temp[i - low];

        return c;
    }
    int mergesort(vector<int> &a, int low, int high)
    {
        int c = 0;

        if (low >= high)
            return c;

        int mid = (low + high) / 2;
        c += mergesort(a, low, mid);
        c += mergesort(a, mid + 1, high);
        c += merge(a, low, mid, high);

        return c;
    }
    int countPairs(int arr[], int n)
    {
        // Your code goes here
        vector<int> a;
        for (int i = 0; i < n; i++)
            a.push_back(i * arr[i]);

        return mergesort(a, 0, n - 1);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countPairs(a, n) << endl;
    }
}
// } Driver Code Ends