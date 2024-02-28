/*513. Find Bottom Left Tree Value

https://leetcode.com/problems/find-bottom-left-tree-value/

Given the root of a binary tree, return the leftmost value in the last row of the tree.



Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7

 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *ans = NULL;
        while (!q.empty())
        {
            ans = q.front();
            q.pop();

            if (ans->right)
                q.push(ans->right);
            if (ans->left)
                q.push(ans->left);
        }
        return ans->val;
    }
};