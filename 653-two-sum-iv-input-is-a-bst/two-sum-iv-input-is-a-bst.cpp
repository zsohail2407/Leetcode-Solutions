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
    TreeNode* aaa(TreeNode* current, int k)
    {
        while(current!=nullptr)
        {
            if(current->val==k)
            {
                return current;
            }
            else if(current->val>k){current=current->left;}
            else {current=current->right;}
        }
        return nullptr;
    }

    bool aaaa2(TreeNode* a, TreeNode* root,int k)
    {
        if(a==nullptr)
        {
            return false;
        }
        TreeNode* abc=aaa(root,k-a->val);
        if(abc && abc!=a)
        {
            return true;
        }
        return aaaa2(a->left,root,k)||aaaa2(a->right,root,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return aaaa2(root, root, k);
    }
};