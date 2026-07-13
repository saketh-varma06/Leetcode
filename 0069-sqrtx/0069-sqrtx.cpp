class Solution {
public:
    int mySqrt(int x) {
        int l=1,h=x;
        while(l<=h){
            long long mid=l+(h-l)/2;
            long long val=(mid*mid);
            if(val<=x){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return h;
    }
};