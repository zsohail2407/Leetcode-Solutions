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
vector<int> ordered;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left);
        ordered.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for(int i=0;i<ordered.size();i++)
        {
            for(int j=i+1;j<ordered.size();j++)
            {
              if(ordered[i]+ordered[j]==k)
              {
                return true;
              }
            }
        }
        return false;
    }
};