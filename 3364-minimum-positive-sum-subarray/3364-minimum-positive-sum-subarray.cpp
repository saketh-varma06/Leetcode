class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int lo=0,h=0,sum=0,ans=INT_MAX;
        while(h<nums.size()){
            sum+=nums[h];
            if((h-lo+1)>r){
                sum-=nums[lo];
                lo++;
            }
            for(int i=lo;i<=h;i++){
                int len=h-i+1;
                if(len>=l && len<=r){
                    int curr=sum;
                    for(int j=lo;j<i;j++){
                        curr-=nums[j];
                    }
                    if(curr>0){
                        ans=min(ans,curr);
                    }
                }
            }
            h++;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};