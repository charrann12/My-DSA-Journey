//problem : https://leetcode.com/problems/same-tree/description/
// approach: recursively applying this : if both are null then it is, if any one is not null then its not(use || case)
//          if node->val is not equal 


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
        if(!p || !q) return false;
        if(p->val!=q->val) return false;

       return  isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};