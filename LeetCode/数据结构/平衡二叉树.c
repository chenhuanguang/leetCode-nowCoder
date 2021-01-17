/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int BTreeHigh(struct TreeNode* root)
{
    if (root == NULL)
	{
		return 0;
	}
    int left = BTreeHigh(root->left);
	int right = BTreeHigh(root->right);
    
    return left > right ? left + 1 : right + 1;
}

bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }

    return abs(BTreeHigh(root->left) - BTreeHigh(root->right)) < 2
            && isBalanced(root->left) 
            && isBalanced(root->right);
}