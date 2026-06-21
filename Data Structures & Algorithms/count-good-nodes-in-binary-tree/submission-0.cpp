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
    int go(TreeNode* root, int maxi){
        if(root){
            int ans = 0;
            if(maxi <= root->val){
                ans = 1;
                maxi = root->val;
            }
            ans += go(root->left, maxi);
            ans += go(root->right, maxi);
            return ans;
        }
        return 0;
    }
    int goodNodes(TreeNode* root) {
        return go(root, INT_MIN);
    }
};
