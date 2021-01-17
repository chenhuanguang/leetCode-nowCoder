/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //判断两棵树是否相同
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    return p->val == q->val
    && isSameTree(p->left, q->left)
    && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL)
        return false;
    if(t == NULL)
        return true;
    //存在相同的结构，就直接返回。
    if (isSameTree(s, t) == true)
        return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}