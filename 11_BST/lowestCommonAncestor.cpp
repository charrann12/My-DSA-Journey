//problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
//intuition: runs for the BT code too but for an optimised code we need to use the conditions in the code 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root ==NULL) return root;

        if(p->val <root->val && q->val <root->val){
            
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val >root->val && q->val>root->val){
          return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};