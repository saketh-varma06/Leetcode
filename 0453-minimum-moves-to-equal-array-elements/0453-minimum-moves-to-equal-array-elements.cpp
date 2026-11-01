class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long cnt=0;
        int mini=nums[0];
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            cnt+=nums[i];
        }
        return cnt-(1LL*nums.size()*mini);
    }
};