/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* mirrorTree(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}
