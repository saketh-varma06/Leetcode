class Solution {
public:
    bool possible(vector<int>& price,int k,int mid){
        int cnt=1,last=price[0];
        for(int i=1;i<price.size();i++){
            if(price[i]-last>=mid){
                cnt++;
                last=price[i];
                if(cnt>=k)  return true;
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size();
        int l=1,h=price[n-1]-price[0];
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(price,k,mid)){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return h;
    }
};