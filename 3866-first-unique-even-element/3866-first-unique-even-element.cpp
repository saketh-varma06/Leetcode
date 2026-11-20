class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int num:nums){
            if(num%2==0)
                mpp[num]++;
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                if(mpp[nums[i]]==1){
                    ans=nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};