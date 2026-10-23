class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int x=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                x&=nums[i];
            }
        }
        return max(0,x);
    }
};