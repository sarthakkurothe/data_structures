/*Kth common ancestor in BST

https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1

Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

Nodes x and y will always be present in the input of a BST, and x != y.

Example 1:

Input:
Input tree

k = 2, x = 40, y = 60
Output:
30
Explanation:
Their 2nd common ancestor is 30.
Example 2:

Input:
Input tree

k = 2, x = 40, y = 60
Output:
-1
Explanation:
LCA of 40 and 60 is 50, which is root itself. There does not exists 2nd common ancestor in this case.
Your task :
You don't have to read input or print anything. Your task is to complete the function kthCommonAncestor() that takes the root of the tree, k, x and y as input and returns the kth common ancestor of x and y.

Expected Time Complexity: O(Height of the Tree)
Expected Space Complexity: O(Height of the Tree)

Your Task :
1 <= n, k <= 105
1 <= node->data, x, y <= 109

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution
{
public:
    int fun(Node *root, int x, int y, int &k)
    {
        if (root == NULL)
        {
            return -1;
        }
        int val = -1;
        if ((root->data > x) && (root->data) > y)
        {
            val = fun(root->left, x, y, k);
        }
        else if ((root->data < x) && (root->data < y))
        {
            val = fun(root->right, x, y, k);
        }
        k--;
        if (k == 0)
        {
            val = root->data;
        }
        return val;
    }
    int kthCommonAncestor(Node *root, int k, int x, int y)
    {
        return fun(root, x, y, k);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {

        string inp;
        getline(cin, inp);

        int k, x, y;
        cin >> k >> x >> y;
        cin.ignore();

        struct Node *root = buildTree(inp);

        Solution ob;
        int ans = ob.kthCommonAncestor(root, k, x, y);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends