/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// void Swap(struct TreeNode* root)
// {
//     if (root == NULL)
//         return;
//     struct TreeNode* tmp = root->left;
//     root->left = root->right;
//     root->right = tmp;

//     Swap(root->left);
//     Swap(root->right);
// }

// struct TreeNode* invertTree(struct TreeNode* root)
// {
//     if (root == NULL)
//         return NULL;
//     Swap(root);
//     return root;
// }

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}