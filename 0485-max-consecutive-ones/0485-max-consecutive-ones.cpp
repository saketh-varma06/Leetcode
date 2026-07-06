class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0,max_count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                count++;
                max_count=max(max_count,count);
            if(nums[i]==0){
                count=0;
            }
        }
        return max_count;
    }
};