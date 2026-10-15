class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            bool st[101]={false};
            int cnt=0;
            for(int j=i;j<nums.size();j++){
                if(!st[nums[j]]){
                    st[nums[j]]={true};
                    cnt++;
                }
                ans+=cnt*cnt;
            }
        }
        return ans;
    }
};