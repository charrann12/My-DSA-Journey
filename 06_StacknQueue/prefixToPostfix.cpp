bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch =='*' || ch =='/' ;
}

string preToPost(string s){
    reverse(s.begin(), s.end());
    stack<string>st;
    for(char ch:s){
        if(isOperator(ch)){
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string expr = t1+t2+ch;
            st.push(expr);
        }
        else{
            st.push(string(1,ch));
        }
    }
    return st.top();
}