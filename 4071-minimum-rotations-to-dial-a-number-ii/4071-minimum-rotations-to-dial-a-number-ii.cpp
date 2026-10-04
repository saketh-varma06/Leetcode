class Solution {
public:
    int minRotations(int n, string s) {
        int sum=abs(s[0]-'0');
        sum=min(sum,10-sum);
        for(int i=1;i<s.length();i++){
            int diff=abs(s[i]-s[i-1]);
            diff=min(diff,10-diff);
            sum+=diff;
        }
        int ans=sum;
        for(int k=0;k<n;k++){
            int sum2=sum;
            if(k==0){
                int old=abs(s[0]-'0');
                old=min(old,10-old);
                sum2-=old;
                int first=abs(s[n-1]-'0');
                first=min(first,10-first);
                sum2+=first;
            }
            else{
                int old=abs(s[k]-s[k-1]);
                old=min(old,10-old);
                int diff=abs(s[n-1]-s[k-1]);
                diff=min(diff,10-diff);
                sum2-=old;
                sum2+=diff;
            } 
            ans=min(ans,sum2);
        }
        return ans;
    }
};