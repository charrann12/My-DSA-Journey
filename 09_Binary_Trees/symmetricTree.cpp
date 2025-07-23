// problem: https://leetcode.com/problems/symmetric-tree/description/
// intuition: using double recursion 


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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || helperFunc(root->left, root->right);
    }

    bool helperFunc(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;

        if(left->val != right->val) return false;

        return helperFunc(left->left, right->right) && helperFunc(left->right, right->left);
    }
};