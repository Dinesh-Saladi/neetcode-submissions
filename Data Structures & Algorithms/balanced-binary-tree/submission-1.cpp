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
    int go(TreeNode* root, bool &ans){
        if(root){
            int l = go(root->left, ans);
            int r = go(root->right, ans);
            ans = ans & (abs(l-r) <= 1);
            return max(l, r)+1;
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        go(root, ans);
        return ans;
    }
};
