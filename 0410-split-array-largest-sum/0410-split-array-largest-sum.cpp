class Solution {
public:
    int func(vector<int>& nums, int k){
        int stud=1,pagest=0;
        for(int i=0;i<nums.size();i++){
            if(pagest+nums[i]<=k){
                pagest+=nums[i];
            }
            else{
                stud++;
                pagest=nums[i];
            }
        }
        return stud;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int noofstud=func(nums,mid);
            if(noofstud>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};