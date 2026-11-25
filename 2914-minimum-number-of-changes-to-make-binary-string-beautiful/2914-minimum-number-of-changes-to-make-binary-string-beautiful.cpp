class Solution {
public:
    int minChanges(string s) {
        int l=0,r=1,ans=0;
        while(r<s.size()){
            if(s[l]!=s[r])
                ans++;
            l+=2;
            r+=2;
        }
        return ans;
    }
};