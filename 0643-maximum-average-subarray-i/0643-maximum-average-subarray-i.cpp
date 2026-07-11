class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum=INT_MIN;
        int l=0,r=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while((r-l+1)>k){
                sum-=nums[l];
                l++;
            }
            if((r-l+1)==k){
                max_sum=max(max_sum,sum);
            }
            r++;
        }
        return (double)max_sum/k;
    }
};