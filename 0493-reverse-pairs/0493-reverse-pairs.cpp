class Solution {
public:
    void mergesort(vector<int>&nums,int low,int mid,int high){
        vector<int>temp;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=low;k<=high;k++){
            nums[k]=temp[k-low];
        }
    }
    int countpairs(vector<int>&nums,int low,int mid,int high){
        int j=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2LL*nums[j]) j++;
            cnt+=(j-(mid+1));
        }
        return cnt;
    }
    int merge(vector<int>&nums,int low,int high){
        int cnt=0;
        if(low>=high)   return cnt;
        int mid=(low+high)/2;
        cnt+=merge(nums,low,mid);
        cnt+=merge(nums,mid+1,high);
        cnt+=countpairs(nums,low,mid,high);
        mergesort(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);
    }
};