bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch =='*' || ch =='/' ;
}

string prefixToInfix(string s){
    reverse(s.begin(), s.end());
    stack<string>st;
    if(st.size()<2) return "invalid prefix expression";
    for(char ch:s){
        if(isOperator(ch)){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            st.push(expr);
        }
        else{
            st.push(string(1,ch));
        }
    }
    return st.top();
}