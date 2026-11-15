class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum=0,odd=0,even=1,cnt=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2!=0){
                cnt=(cnt+even)%mod;
                odd++;
            }
            else{
                cnt=(cnt+odd)%mod;
                even++;
            }
        }
        return cnt;
    }
};