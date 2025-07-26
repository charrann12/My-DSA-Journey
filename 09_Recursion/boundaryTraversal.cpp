//problem: https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
// intuition: we will first calculate the left boundary then right boundary then leaves
// check for the root not to be leaves so that they can be considered either as left or right boundary 
// from root keep moving left for boundary if doesnt exist then go right 
// same goes with the right 

// 1 check for leaf
bool isLeaf(TreeNode* root){
    return !root->left && !root->right;
}

// 2 left boundary traversal

void addLeftBoundary(TreeNode* root, vector<int>&res){
    TreeNode* curr = root ->left;
    while(curr){
        if(!isLeaf){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else curr = curr->right;
    }

}

void addRightBoundary(TreeNode* root, vector<int>&res){
    TreeNode* curr - root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf){
            temp.push_back(root->data);
        }
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

for(int i = temp.size()-1;i>=0;--i){
    res.push_back(temp[i]);
}
}

void addLeaves(TreeNode* root, vector<int>&res){
    if(isLeaf){
        res.push_back(root->data);
        return;
    }

    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);

}


void printBoundary(TreeNode* root){
    vector<int>res;
    if(!root){
        return res;
    }
    if(!isLeaf(root)){
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}