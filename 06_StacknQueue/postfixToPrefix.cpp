bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch =='*' || ch =='/' ;
}

string postfixToPrefix(string s){
    stack<string>st;
    for(char ch:s){
        if(isOperator(ch)){
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string expr =  ch + t2 + t1 ;
            st.push(expr);
        }
        else{
            st.push(string(1,ch));
        }
    }
    return st.top();
}