class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        vector<int>res;
        int sum=0;
        for(int i:nums){
            mpp[i]++;
        }
        for(auto it:mpp){
            sum+=it.first;
            if(it.second==2){
                res.push_back(it.first);
            }
        }
        int miss=(n*(n+1)/2)-sum;
        res.push_back(miss);
        return res;
    }
};