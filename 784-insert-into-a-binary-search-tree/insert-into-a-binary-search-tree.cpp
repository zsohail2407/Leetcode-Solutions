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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
       // while (temp!=nullptr)
        //{
            if(root==nullptr)
            {
                return new TreeNode(val);
            }
            if(temp->val>val)
            {
               temp->left=insertIntoBST(temp->left,val);
            }
            else
            {
               temp->right=insertIntoBST(temp->right,val);
            }
        //}
        return root;
    }
};