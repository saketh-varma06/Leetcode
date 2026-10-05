class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int score=0,n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                st.push(0);
            }
            else{
                int x=st.top();
                st.pop();
                if(x==0)            x=1;
                else                x=2*x;
                if(!st.empty()){
                    x+=st.top();
                    st.pop();
                    st.push(x); //these 3 lines can be written like this st.top()+=x;
                } 
                else{
                    st.push(x);
                }      
            }
        }
        return st.top();
    }
};