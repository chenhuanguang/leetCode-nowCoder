/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* root, int val)
{
    if (root)
    {
        return root-> val == val
        &&helper(root->left, val)
        &&helper(root->right, val);
    }
    return true;
}

bool isUnivalTree(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    return helper(root, root->val);
}