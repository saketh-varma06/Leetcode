class Solution {
public:
    int findmax(vector<int>& piles){
        int maxi=0;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calculatetotalhours(vector<int>& piles,int hourly){
        long long totalhrs=0;
        for(int i=0;i<piles.size();i++){
            totalhrs+=(piles[i]+hourly-1)/hourly;
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,high=findmax(piles),ans=INT_MAX;
        while(l<=high){
            int mid=l+(high-l)/2;
            long long totalhrs=calculatetotalhours(piles,mid);
            if(totalhrs<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};