class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        int l=0,r=0,n=nums.size(),sum=0,cnt=0;
        while(r<n){
            if(goal<0)  return 0;
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};