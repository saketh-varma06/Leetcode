class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            int l=0,h=arr2.size()-1;
            bool flag=true;
            while(l<=h){
                int mid=l+(h-l)/2;
                int diff=arr1[i]-arr2[mid];
                if(abs(diff)<=d){
                    flag=false;
                    break;
                }
                else{
                    if(diff<0){
                        h=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};