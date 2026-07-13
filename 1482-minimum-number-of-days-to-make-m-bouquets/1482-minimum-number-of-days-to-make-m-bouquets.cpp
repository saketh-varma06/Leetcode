class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m,int k){
        int cnt=0,noofB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noofB+=(cnt/k);
                cnt=0;
            }
        }
        noofB+=(cnt/k);
        return noofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=1LL*k*m;
        if(val>bloomDay.size())     return -1;
        int mini=INT_MAX,maxi=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int l=mini,h=maxi;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(bloomDay,mid,m,k)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};