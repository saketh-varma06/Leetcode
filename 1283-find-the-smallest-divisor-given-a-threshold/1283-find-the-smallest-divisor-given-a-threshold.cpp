class Solution {
public:
    int sumbyD(vector<int>& nums,int div){
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=ceil((double)(nums[i])/(double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(sumbyD(nums,mid)<=threshold){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};