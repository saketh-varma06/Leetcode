class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        long long sum=cost1+cost2;
        int cnt=min(need1,need2);
        ans+=(long long)cnt*min(sum,(long long)costBoth);
        need1-=cnt,need2-=cnt;
        if(need1>0){
            ans+=(long long)need1*min(cost1,costBoth);
            need1--;
        }
        if(need2>0){
            ans+=(long long)need2*min(cost2,costBoth);
            need2--;
        }
        return ans;
    }
};