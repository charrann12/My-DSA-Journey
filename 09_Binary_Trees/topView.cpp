
vector<int>topView(TreeNode* root){
    vector<int>ans;
    if(!root) return ans;

    map<int, int> topNode;
    queue<pair<TreeNode*, int>>q;

    q.push({root, 0});

    while(!q.empty()){
        auto [node, hd] = q.front();
        q.pop();

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = node->val;
        }
        if(node->left){
            q.push({node->left, hd-1});
        }

        if(node->right){
            q.push({node->right, hd+1});
                    }
       
    }
     for(auto it: topNode){
            ans.push_back(it.second);
        }
    return ans;
}