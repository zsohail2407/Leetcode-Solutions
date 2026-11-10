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
    void inorder(TreeNode* root, int k,int& ct,int& res)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left,k,ct,res);
        if(ct>=k)
        {
            return;
        }
        ct++;
        if(ct==k)
        {
            res=root->val;
            return;
        }
        inorder(root->right,k,ct,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ct=0;
        int res=-1;
        inorder(root,k,ct,res);
        return res;
    }
};