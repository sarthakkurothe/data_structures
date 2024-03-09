/* Find the N-th character

 Given a binary string s. Perform r iterations on string s, where in each iteration 0 becomes 01 and 1 becomes 10. Find the nth character (considering 0 based indexing) of the string after performing these r iterations (see examples for better understanding).

Example 1:

Input:
s = "1100"
r = 2
n = 3
Output:
1
Explanation:
After 1st iteration s becomes "10100101".
After 2nd iteration s becomes "1001100101100110".
Now, we can clearly see that the character at 3rd index is 1, and so the output.
Example 2:

Input:
s = "1010"
r = 1
n = 2
Output:
0
Explanation :
After 1st iteration s becomes "10011001".
Now, we can clearly see that the character at 2nd index is 0, and so the output.
Your task:
You don't need to read input or print anything. Your task is to complete the function nthCharacter() which takes the string s and integers r and n as input parameters and returns the n-th character of the string after performing r operations on s.

Expected Time Complexity: O(r*|s|)
Expected Auxilary Space: O(|s|)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {
        string b = s;
        for (int i = 0; i < r; i++)
        {
            string a = "";
            for (int i = 0; i < n + r; i++)
            {
                if (b[i] == '0')
                    a += "01";
                else if (b[i] == '1')
                    a += "10";
            }
            b = a;
        }
        return b[n];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends