/*Largest subsquare surrounded by X

https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1

Given a square matrix a of size n x n, where each cell can be either 'X' or 'O', you need to find the size of the largest square subgrid that is completely surrounded by 'X'. More formally you need to find the largest square within the grid where all its border cells are 'X'.

Example 1:

Input:
n = 2
a = [[X,X],
     [X,X]]
Output:
2
Explanation:
The largest square submatrix
surrounded by X is the whole
input matrix.
Example 2:

Input:
n = 4
a = [[X,X,X,O],
     [X,O,X,X],
     [X,X,X,O],
     [X,O,X,X]]
Output:
3
Explanation:
Here,the input represents following
matrix of size 4 x 4
X X X O
X O X X
X X X O
X O X X
The square submatrix starting at
(0,0) and ending at (2,2) is the
largest submatrix surrounded by X.
Therefore, size of that matrix would be 3.
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestSubsquare() which takes the integer n and the matrix a as input parameters and returns the size of the largest subsquare surrounded by 'X'.

Expected Time Complexity: O(n2)
Expected Auxillary Space: O(n2)

Constraints:
1 <= n <= 1000
a[i][j] belongs to {'X','O'}

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
    int largestSubsquare(int n, vector<vector<char>> mat)
    {
        int vertical_col[n][n];
        int horizontal_row[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vertical_col[i][j] = 0;
                horizontal_row[i][j] = 0;
                if (mat[i][j] == 'X')
                {
                    vertical_col[i][j] = i == 0 ? 1 : vertical_col[i - 1][j] + 1;
                }
                if (mat[i][j] == 'X')
                {
                    horizontal_row[i][j] = j == 0 ? 1 : horizontal_row[i][j - 1] + 1;
                }
            }
        }

        int maxSquareSide = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vertical_col[i][j] == 0 || horizontal_row[i][j] == 0)
                {
                    continue;
                }
                int curr_side = min(vertical_col[i][j], horizontal_row[i][j]);
                while (curr_side > 0)
                {
                    int v_pnt = i - curr_side + 1;
                    int h_pnt = j - curr_side + 1;
                    if (horizontal_row[v_pnt][j] >= curr_side && vertical_col[i][h_pnt] >= curr_side)
                    {
                        maxSquareSide = max(maxSquareSide, curr_side);
                        break;
                    }
                    curr_side--;
                }
            }
        }
        return maxSquareSide;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends