class Solution {
public:
    int lower_bound(vector<int>& nums, int n, int target){
        int l=0,h=n-1,ans=n;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>=target){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int>& nums, int n, int target){
        int l=0,h=n-1,ans=n;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>target){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower_bound(nums,nums.size(),target);
        int ub=upper_bound(nums,nums.size(),target);
        if(lb==nums.size() || nums[lb]!=target)     return {-1,-1};
        return {lb,ub-1};
    }
};