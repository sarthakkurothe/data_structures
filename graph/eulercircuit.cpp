/*Euler Circuit in an Undirected Graph

https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex. Given the number of vertices v and adjacency list adj denoting the graph. Find that there exists the Euler circuit or not. Return 1 if there exist  alteast one eulerian path else 0.

Example 1:

Input:
v = 4
edges[] = {{0, 1},
           {0, 2},
           {1, 3},
           {2, 3}}

Output:
1
Explanation: corresponding adjacency list will be {{1, 2},{0, 3},{0, 3},{1, 2}}
One of the Eularian circuit
starting from vertex 0 is as follows:
0->1->3->2->0
Example 2:

Input:
v = 3
edges[] = {{0, 1},
         {0, 2}}


Output:
0
Explanation: corresponding adjacency list will be {{1, 2}}
No Eulerian path is found.
Your Task:
You don't need to read or print anything. Your task is to complete the function isEularCircuitExist() which takes v and adjacency list adj[] as input parameter and returns boolean value 1 if Eular circuit exists otherwise returns 0.

Expected Time Complexity: O(v + e)
Expected Space Complexity: O(v)

Constraints:
1 <= v <= 105
1 <= edges <= 2*105

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isEularCircuitExist(int v, vector<int> adj[])
    {
        for (int i = 0; i < v; i++)
        {
            if (int(adj[i].size()) % 2 == 1)
            {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isEularCircuitExist(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends