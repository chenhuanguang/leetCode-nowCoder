/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* cur, stack<TreeNode*>& st)
    {
        if (root == nullptr)
            return false;
        st.push(root);
        //判断当前节点是否为要查找的结点
        if (root == cur)
            return true;
        //不是就查看它的左右子树
        if (getPath(root->left, cur, st))
            return true;
        if (getPath(root->right, cur, st))
            return true;
        //当前的root不再需要查找的路径上
        st.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        stack<TreeNode*> path1;
        stack<TreeNode*> path2;
        getPath(root, p, path1);
        getPath(root, q, path2);
        while (path1.size() != path2.size())
        {
            if (path1.size() > path2.size())
                path1.pop();
            else
                path2.pop();
        }
        while (path1.top() != path2.top())
        {
            path1.pop();
            path2.pop();
        }
        return path1.top();
    }
};