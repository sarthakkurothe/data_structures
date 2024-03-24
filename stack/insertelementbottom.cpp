/*Insert an Element at the Bottom of a Stack

https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack.

Note: Everywhere in this problem, the bottommost element of the stack is shown first while priniting the stack.

Example 1:

Input:
n = 5
x = 2
st = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
Example 2:

Input:
n = 3
x = 4
st = {5,3,1}
Output:
{4,5,3,1}
Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.
Your Task:

You don't need to read input or print anything. Your task is to complete the function insertAtBottom() which takes a stack st and an integer x as inputs and returns the modified stack after insertion.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
0 <= x, elements of stack <= 109
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    stack<int> insertAtBottom(stack<int> st, int x)
    {
        stack<int> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        temp.push(x);
        st.empty();
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return st;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        cin >> x;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp = ob.insertAtBottom(st, x);
        vector<int> v;
        while (tmp.size())
        {
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends