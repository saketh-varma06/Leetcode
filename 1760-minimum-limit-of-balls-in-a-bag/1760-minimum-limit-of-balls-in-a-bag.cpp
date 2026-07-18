class Solution {
public:
    bool ballsweplace(vector<int>& nums, int mid,int maxi){
        int n=nums.size(),cntoperations=0;
        for(int i=0;i<n;i++){
            cntoperations+=(nums[i]-1)/mid;
        }
        if(cntoperations<=maxi) return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1,h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(ballsweplace(nums,mid,maxOperations)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};