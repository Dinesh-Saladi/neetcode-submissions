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
    bool go(TreeNode* root, int maxi, int mini){
        if(root){
            if(root->val >= maxi || root->val <= mini) return false;
            bool l = go(root->left, root->val, mini);
            bool r = go(root->right, maxi, root->val);
            return l && r;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return go(root, INT_MAX, INT_MIN);
    }
};
