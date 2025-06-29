bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch =='*' || ch =='/' ;
}

string postFixtoInfix(string s){
    stack<string>st;
    
    for(char ch:s){
        if(isOperator(ch)){
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string expr = "(" + op1 +ch+ op2 +")";
            st.push(expr); 
        }
        else{
            st.push(string(1,ch));
        }
    }
    return st.top();
}