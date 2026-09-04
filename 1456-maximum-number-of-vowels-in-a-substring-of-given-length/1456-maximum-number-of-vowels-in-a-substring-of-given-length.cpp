class Solution {
public:
    bool vowel(char ch){
        return true ? ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' : false;
    }
    int maxVowels(string s, int k) {
        int l=0,r=0,cnt=0,max_cnt=0;
        while(r<s.size()){
            if(vowel(s[r])){
                cnt++;
            }
            if((r-l+1)>k){
                if(vowel(s[l])){
                    cnt--;
                }
                l++;
            }
            max_cnt=max(max_cnt,cnt);
            r++;
        }
        return max_cnt;
    }
};