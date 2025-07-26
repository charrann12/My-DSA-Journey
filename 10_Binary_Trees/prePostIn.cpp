/*
approach: single stack containing root value and its num
*/


vector<int>prePostIn(TreeNode* root){
    stack<pair<TreeNode*, int>>st;
    st.push({root,1});

    vector<int>pre,post,in;
    if(root==NULL) return;

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        //for pre order
        //increment 1 to 2
        //if left exists push

        if(it.second == 1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }
        //for inorder
        //incre
        //if right exists push

        else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL){
                st.push({it.first->right, 1});
            }
        }
        //for postorder

        else{
            post.push_back(it.first->val);
        }
    }
}