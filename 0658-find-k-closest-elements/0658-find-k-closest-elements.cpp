class Solution {
public:
    int lower_bound(vector<int>& arr, int x){
        int n=arr.size();
        int ans=n;
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]>=x){
                ans=mid;
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int right=lower_bound(arr,x);
        int left=right-1;
        while(k--){
            if(left<0){
                right++;
            }
            else if(right>=n){
                left--;
            }
            else if(x-arr[left]<=arr[right]-x){
                left--;
            }
            else {
                right++;
            }
        }
        return {arr.begin()+left+1,arr.begin()+right};
    }
};