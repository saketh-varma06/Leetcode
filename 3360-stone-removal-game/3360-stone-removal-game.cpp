class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)        return false;
        int temp=10,cnt=0;
        while(n>0 && n>=temp){
            n-=temp;
            temp--;
            cnt++;
        }
        return cnt%2==1;
    }
};