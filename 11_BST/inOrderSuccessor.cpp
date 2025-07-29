// problem: https://www.youtube.com/watch?v=SXKAD2svfmI
//intuition : compare the root with the val and move accordingly. keep successor on null
//  whenever u encounter a number bigger than val save it and move left in search for a 
// smaller one than that  

TreeNode* inOrderSuccesor(TreeNode* root, TreeNode* q){
    TreeNode* successor = NULL;
    while(root!=NULL){
        if(root->val >= q->val){
            successor = root->val;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return successor;
}

TreeNode* inOrderPredecessor(TreeNode* root, TreeNode* q){
    TreeNode* predecessor = NULL;
    while(root!=NULL){
        if(root->val<=q->val){
            predecessor = root->val;
            root = root->left;

        }
        else{
            root = root->right;
        }
    }
    return predecessor;
}
