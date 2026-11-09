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
    bool isValidBST(TreeNode* root)
    {
    return check(root,nullptr,nullptr);
    }
    bool check(TreeNode* node,TreeNode* left,TreeNode* right)
    {
        if (node==nullptr)
        {
            return true;
        }
        //else
        //{
        if(left && node->val<=left->val)
        {
           return false;
        }
        if(right && node->val>=right->val)
        {
            return false;
        }
        return check(node->left,left,node) &&
        check(node->right,node,right);
        //}
    }
};