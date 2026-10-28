class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(),cnt=0,sum=0,ans=0;
        while(r<n){
            if(nums[r]%2!=0){
                cnt++;
                sum=0;
            }
            while(cnt==k){
                sum++;
                if(nums[l]%2!=0){
                    cnt--;
                }
                l++;
            }
            ans+=sum;
            r++;
        }
        return ans;
    }
};