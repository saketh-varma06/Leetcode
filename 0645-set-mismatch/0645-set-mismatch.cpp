class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>count(n+1,0);
        vector<int>res;
        int sum=0;
        for(int i:nums){
            count[i]++;
            sum+=i;
        }
        for(int i=1;i<=n;i++){
            if(count[i]==2){
                res.push_back(i);
            }
        }
        int miss=(n*(n+1)/2)-sum;
        res.push_back(miss+res[0]);
        return res;
    }
};