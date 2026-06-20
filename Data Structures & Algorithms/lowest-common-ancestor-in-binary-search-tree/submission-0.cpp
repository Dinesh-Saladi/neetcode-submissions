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
    bool go(TreeNode* root, int tar, vector<TreeNode*>&v){
        if(root){
            if(root->val == tar){
                v.push_back(root);
                return true;
            }
            bool l = go(root->left, tar, v);
            bool r = go(root->right, tar, v);
            if(l || r) v.push_back(root);
            return l || r;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a, b;
        go(root, p->val, a);
        go(root, q->val, b);
        int i = a.size()-1, j = b.size()-1;
        TreeNode* ans = NULL;
        while(i >= 0 && j >= 0 && a[i] == b[j]){
            ans = a[i];
            i--, j--;
        }
        return ans;
    }
};
