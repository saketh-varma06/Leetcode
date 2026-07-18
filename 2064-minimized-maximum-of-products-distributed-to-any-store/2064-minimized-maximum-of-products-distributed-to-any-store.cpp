class Solution {
public:
    bool possible(vector<int>& quantities,int mid,int n){
        int cnt=0;
        for(int i=0;i<quantities.size();i++){
            cnt+=(quantities[i]+mid-1)/mid;
        }
        if(cnt<=n)  return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,h=*max_element(quantities.begin(),quantities.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(quantities,mid,n)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};