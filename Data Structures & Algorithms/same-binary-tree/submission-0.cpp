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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        queue<TreeNode*>q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty()){
            int size = q1.size();
            for(int i=0;i<size;i++){
                TreeNode* t1 = q1.front();
                q1.pop();
                TreeNode* t2 = q2.front();
                q2.pop();
                if(t1->val != t2->val) return false;
                if(t1->left && t2->left){
                    q1.push(t1->left);
                    q2.push(t2->left);
                }else if((t1->left && !t2->left) || (!t1->left && t2->left)) return false;
                if(t1->right && t2->right){
                    q1.push(t1->right);
                    q2.push(t2->right);
                }else if((t1->right && !t2->right) || (!t1->right && t2->right)) return false;
            }
        }
        return true;
    }
};
