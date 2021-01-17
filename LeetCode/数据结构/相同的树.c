/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    //两棵空树
    if (p == NULL && q == NULL)
        return true;
    //有一颗树为空树
    if (p == NULL || q == NULL)
        return false;
    //只有当前两棵树的结点的值相同
    //且他们的左右孩子都相同才是相同的树
    return p->val == q->val
    && isSameTree(p->left, q->left)
    && isSameTree(p->right, q->right);
}