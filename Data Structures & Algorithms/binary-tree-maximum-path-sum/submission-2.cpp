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
    int go(TreeNode* root, int &ans){
        if(root){
            int l = go(root->left, ans);
            int r = go(root->right, ans);
            ans = max(ans, l+r+root->val);
            return max(0, max(l, r) + root->val);
        }
        return 0;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        go(root, ans);
        return ans;
    }
};
