// problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// intuition: checking both the subtrees. If found return the node else check if that exists in left or gith subtree


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
        if((root == p) || (root == q) || root==NULL){
            return root;
        }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p,q);

    if(left && right) return root;

    return left?left: right;
    }
};