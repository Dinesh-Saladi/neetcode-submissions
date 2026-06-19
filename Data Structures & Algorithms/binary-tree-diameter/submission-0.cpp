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
            ans = max(ans, l + r);
            return max(l, r)+1;
        }
        return 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        go(root, ans);
        return ans;
    }
};
