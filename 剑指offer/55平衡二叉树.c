/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// int BTreeHigh(struct TreeNode* root)
// {
//     if (root == NULL)
// 	{
// 		return 0;
// 	}
//     int left = BTreeHigh(root->left);
// 	int right = BTreeHigh(root->right);
    
//     return left > right ? left + 1 : right + 1;
// }

// bool isBalanced(struct TreeNode* root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     return abs(BTreeHigh(root->left) - BTreeHigh(root->right)) <=1 && isBalanced(root->left) && isBalanced(root->right);
// }
int res(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = res(root->left);
    if (left == -1)
    {
        return -1;
    }
    int right = res(root->right);
    if (right == -1)
    {
        return -1;
    }

    if (abs(left - right) < 2)
    {
        return left > right ? left + 1 : right + 1;
    }

    return -1;
}

bool isBalanced(struct TreeNode* root)
{
    return res(root) != -1;
}