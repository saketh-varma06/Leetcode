class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,pro=1;
        int t=n;
        while(t>0){
            int rem=t%10;
            sum+=rem;
            pro*=rem;
            t/=10;
        }
        return n%(pro+sum)==0;
    }
};