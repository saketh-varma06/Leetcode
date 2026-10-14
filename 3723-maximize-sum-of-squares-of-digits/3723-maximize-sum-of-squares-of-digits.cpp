class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)       return "";
        string ans;
        ans.reserve(num);
        while(num--){
            int digit=min(9,sum);
            ans+=to_string(digit);
            sum-=digit;
        }
        return ans;
    }
};