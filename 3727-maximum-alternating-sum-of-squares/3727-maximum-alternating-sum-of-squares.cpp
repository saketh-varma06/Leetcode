class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int maxi=0;
        for(int num:nums){
            maxi=max(maxi,abs(num));
        }
        vector<int>freq(maxi+1,0);
        for(auto num:nums){
            freq[abs(num)]++;
        }
        int pos=0;
        long long sum=0;
        for(int i=0;i<=maxi;i++){
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