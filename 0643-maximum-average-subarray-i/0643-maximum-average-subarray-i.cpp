class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg,max_avg=INT_MIN;
        int l=0,r=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while((r-l+1)>k){
                sum-=nums[l];
                l++;
            }
            if((r-l+1)==k){
                avg=(double)(sum)/k;
                max_avg=max(max_avg,avg);
            }
            r++;
        }
        return max_avg;
    }
};