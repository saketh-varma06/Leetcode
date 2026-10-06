class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.length()==0)     return 0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};