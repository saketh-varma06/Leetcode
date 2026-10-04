class Solution {
public:
    int minRotations(string s) {
        int sum=abs(s[0]-'0');
        sum=min(sum,10-sum);
        for(int i=1;i<s.length();i++){
            int diff=abs(s[i]-s[i-1]);
            diff=min(diff,10-diff);
            sum+=diff;
        }
        return sum;
    }
};