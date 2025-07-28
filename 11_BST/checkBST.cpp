//problem: https://leetcode.com/problems/validate-binary-search-tree/description/
//intuition: inorder traversal and check whether the values are in ascending order or not 

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
vector<int>ans;
void inOrder(TreeNode* root){
    
    if(!root) return;

    inOrder(root->left);
    ans.push_back(root->val);
    inOrder(root->right);
    
  
}
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i =1 ;i<ans.size();i++){
            if(ans[i] <= ans[i-1]) return false;
        }
        return true;
    }
};