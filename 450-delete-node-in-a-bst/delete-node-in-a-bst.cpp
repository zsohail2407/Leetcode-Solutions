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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev=nullptr;
        TreeNode* c=root;
        while(c && c->val!=key)
        {
            prev=c;
            if(key<c->val)
            {
                c=c->left;
            }
            else
            {
                c=c->right;
            }
        }
            if(c==nullptr)
            {
                return root;
            }
            if(c->left && c->right)
            {
                TreeNode* t1=c;
                TreeNode* t=c->right;
                while(t->left)
                {
                    t1=t;
                    t=t->left;
                }
                c->val=t->val;
                prev=t1;
                c=t;
            }
            TreeNode* temp=nullptr;
            if(c->left !=nullptr)
            {
                temp=c->left;
            }
            else
            {
                temp=c->right;
            }
            if (prev==nullptr)
            {
                return temp;
            }
            if(prev->left==c)
            {
                prev->left=temp;
            }
            else
            {
                prev->right=temp;
            }
            return root;
        }

};