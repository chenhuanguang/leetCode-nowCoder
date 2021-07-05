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
class Solution {
public:
    void _stree2str(TreeNode* root, string& str)
    {
        if (root)
        {
            //拼接当前节点的数据
            stringstream ss;
            ss << root->val;
            str += ss.str();

            //处理左子树
            if (root->left)
            {
                str += '(';
                _stree2str(root->left, str);
                str += ')';
            }
            else
            {
                //判断右子树是否存在
                if (root->right)
                    str += "()";
                else
                    return;
            }
            if (root->right)
            {
                str += '(';
                _stree2str(root->right, str);
                str += ')';
            }
        }
        
    }

    string tree2str(TreeNode* root)
    {
        string str;
        _stree2str(root, str);
        return str;
    }
};