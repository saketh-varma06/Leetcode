class Solution {
public:
    int maxLength(vector<int>& nums) {
        int l=0,r=0,pro=1,ans=2;
        while(r<nums.size()){
            int x=nums[r];
            while(l<r && gcd(pro,x)>1){
                pro/=nums[l];
                l++;
            }
            pro*=x;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};