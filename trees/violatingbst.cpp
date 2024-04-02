/*Pairs violating the BST property

https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1

Given a binary tree with n nodes, find the number of pairs violating the BST property.
BST has the following properties:-

Every node is greater than its left child and less than its right child.
Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
The maximum in the left sub-tree must be less than the minimum in the right subtree.
Example 1:

Input :
n = 5
Input tree

Output :
5
Explanation :
Pairs violating BST property are:-
(10,50), 10 should be greater than its left child value.
(40,30), 40 should be less than its right child value.
(50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
Example 2:

Input :
n = 6
Input tree

Output :
8
Explanation :
There are total 8 Pairs which violation the BST properties.
Your task :
You don't have to read input or print anything. Your task is to complete the function pairsViolatingBST() that takes the root of the tree and n as input and returns number of pairs violating BST property.

Expected Time Complexity: O(n*logn)
Expected Space Complexity: O(n)

Your Task :
1 <= n <= 2*104
-109 <= node->data <= 109
*/

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
    int merge(int low, int high, int mid, vector<int> &v)
    {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        int cnt = 0;
        while (left <= mid && right <= high)
        {
            if (v[left] <= v[right])
            {
                temp.push_back(v[left]);
                left++;
            }
            else
            {
                temp.push_back(v[right]);
                right++;
                cnt += mid - left + 1;
            }
        }
        while (left <= mid)
        {
            temp.push_back(v[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(v[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
        {
            v[i] = temp[i - low];
        }
        return cnt;
    }

    int mergesort(int low, int high, vector<int> &v)
    {
        int cnt = 0;

        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;

        cnt += mergesort(low, mid, v);
        cnt += mergesort(mid + 1, high, v);
        cnt += merge(low, high, mid, v);
        return cnt;
    }

    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    int pairsViolatingBST(int n, Node *root)
    {
        vector<int> v;
        inorder(root, v);
        return mergesort(0, n - 1, v);
    }
};