/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* left, struct TreeNode* right)
{
    //同时为空，是对称
    if (left == NULL && right == NULL)
        return true;
    //有一方先为空，不对称
    if (left == NULL || right == NULL)
        return false;
    //只有当前访问的两个节点的值相同
    //且左子树的左孩子要和右子树的右孩子也是要对称的（值相同）
    //且左子树的右孩子要和右子树的左孩子也是要对称的（值相同）
    return left->val == right->val
    && helper(left->left, right->right)
    && helper(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    return helper(root->left, root->right);
}