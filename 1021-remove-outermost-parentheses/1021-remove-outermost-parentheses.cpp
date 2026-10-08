class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(cnt==0){
                    s.erase(i,1);
                    i--;
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    s.erase(i,1);
                    i--;
                }
            }
        }
        return s;
    }
};