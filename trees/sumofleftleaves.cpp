/*404. Sum of Left Leaves

https://leetcode.com/problems/sum-of-left-leaves/description/

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
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
void fun(TreeNode *root, int &sum, int &flag)
{
    if (root == 0)
        return;
    if (root->left == 0 && root->right == 0 && flag == 1)
    {
        sum += root->val;
    }
    flag = 1;
    fun(root->left, sum, flag);
    flag = 0;
    fun(root->right, sum, flag);
}

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        int flag = 0;
        fun(root, sum, flag);
        return sum;
    }
};