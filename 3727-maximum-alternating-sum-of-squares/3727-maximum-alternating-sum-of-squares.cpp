class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>freq(40001,0);
        for(auto num:nums){
            freq[abs(num)]++;
        }
        int pos=0;
        long long sum=0;
        for(int i=0;i<=40000;i++){
            while(freq[i]>0){
                long long sq=1LL*i*i;
                if(pos<nums.size()/2){
                    sum-=sq;
                }
                else{
                    sum+=sq;
                }
                pos++;
                freq[i]--;
            }
        }
        return sum;
    }
};