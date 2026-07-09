class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
            xr=xr^(i+1);
        }
        int bitno=0;
        while(1){
            if((xr & (1<<bitno))!=0){
                break;
            }
            bitno++;
        }
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            if((nums[i] & (1<<bitno))!=0){
                one=one^nums[i];
            }
            else{
                zero=zero^nums[i];
            } 
        }
        for(int i=1;i<=n;i++){
            if((i & (1<<bitno))!=0){
                one=one^i;
            }
            else{
                zero=zero^i;
            } 
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==zero)   cnt++;
        }
        if(cnt==2)  return {zero,one};
        return {one,zero};
    }
};