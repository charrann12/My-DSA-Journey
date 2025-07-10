/*
problem: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
approach: using stack 
*/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preOrder;
        if(root == NULL) return preOrder;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            preOrder.push_back(node->val);
            if(node->right!= NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
        }

        return preOrder;
    }
};