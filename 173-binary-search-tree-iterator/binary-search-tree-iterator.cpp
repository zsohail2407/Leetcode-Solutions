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
class BSTIterator {
    stack<TreeNode*> a;
public:
    BSTIterator(TreeNode* root) {
        while(root)
        {
            a.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* root=a.top();
        a.pop();
        TreeNode* aaaa=root->right;
        while(aaaa)
        {
            a.push(aaaa);
            aaaa=aaaa->left;
        }
        return root->val;
    }
    
    bool hasNext() {
        return !a.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */