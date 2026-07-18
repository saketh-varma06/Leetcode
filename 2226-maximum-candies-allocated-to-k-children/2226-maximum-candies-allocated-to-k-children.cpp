class Solution {
public:
    bool candiesweallocate(vector<int>& candies,int mid,long long k){
        int candy=1;
        long long cnt=0;
        for(int i=0;i<candies.size();i++){
            cnt+=(candies[i]/mid);
        }
        if(cnt>=k)   return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        if(accumulate(candies.begin(),candies.end(),0LL)<k)   return 0;
        int l=1,h=*max_element(candies.begin(),candies.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(candiesweallocate(candies,mid,k)){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return h;
    }
};