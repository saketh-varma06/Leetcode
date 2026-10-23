class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,max_dep=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
                max_dep=max(max_dep,cnt);
            }
            else if(s[i]==')'){
                cnt--;
            }
        }
        return max_dep;
    }
};