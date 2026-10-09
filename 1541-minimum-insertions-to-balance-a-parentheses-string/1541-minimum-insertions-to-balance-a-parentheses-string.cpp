class Solution {
public:
    int minInsertions(string s) {
        int cnt=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(cnt%2==1){
                    ans++;
                    cnt--;
                }
                cnt+=2;
            }
            else{
                cnt--;
                if(cnt<0){
                    ans++;
                    cnt=1;
                }
            }
        }
        return ans+cnt;
    }
};