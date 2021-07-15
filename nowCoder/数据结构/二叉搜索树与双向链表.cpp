/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void _Convert(TreeNode* root, TreeNode*& prev)
    {
        if (root)
        {
            _Convert(root->left, prev);
            root->left = prev;
            if (prev)
                prev->right = root;
            prev = root;
            _Convert(root->right, prev);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree) 
    {
        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);
        //找最左结点（链表头）
        TreeNode* cur = pRootOfTree;
        while (cur && cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }
};