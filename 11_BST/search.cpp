//problem: https://leetcode.com/problems/search-in-a-binary-search-tree/description/
// intuition: just check whether the target value is lesser or greater than the root value and traverse accordingly

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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val != val){
            root = val < root->val? root->left: root->right;
        }
        return root;
    }
};