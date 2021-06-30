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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> mat;
        queue<TreeNode*> que;
        //首先给队列中放入第一层节点
        if(root)
            que.push(root);
        while (!que.empty())
        {
            int rowSize = que.size();
            vector<int> row;
            while (rowSize--)
            {
                TreeNode* cur = que.front();
                que.pop();
                row.push_back(cur->val);

                //存入下一层的结点
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            mat.push_back(row);
        }
        return mat;
    }
};