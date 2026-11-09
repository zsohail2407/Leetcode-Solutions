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
    int getMinimumDifference(TreeNode* root) {
       /* if(root==nullptr)
        {
            return -1;
        }
        if(root->left==nullptr)
        {
            return root->val;
        }
        if(root->left->left==nullptr)
        {
            return root->val-root->left->val;
        }
        return getMinimumDifference(root->left);*/
        int minn=100000;
        stack<TreeNode*> treez;
        TreeNode* n1=nullptr;
        TreeNode* n2=root;
        while(n2!=nullptr || !treez.empty())
        {
            while(n2!=nullptr)
            {
                treez.push(n2);
                n2=n2->left;
            }
            n2=treez.top();
            treez.pop();
            if(n1!=nullptr)
            {
            minn=min(minn, n2->val-n1->val);
            }
            n1=n2;
            n2=n2->right;
        }
        return minn;
    }
};