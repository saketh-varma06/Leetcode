class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int l=0,r=0,sum=0;
            string ans="";
            while(r<s.size()){
                sum+=s[r]-'0';
                if((r-l+1)==k){
                    ans+=to_string(sum);
                    sum=0;
                    l=r+1;
                }
                r++;
            }
            if(l<s.size()){
                sum=0;
                while(l<s.size()){
                    sum+=s[l]-'0';
                    l++;
                }
                ans+=to_string(sum);
            }
            s=ans;
        }
        return s;
    }
};