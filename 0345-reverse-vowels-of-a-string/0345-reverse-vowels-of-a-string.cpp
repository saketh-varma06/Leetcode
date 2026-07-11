class Solution {
public:
    string reverseVowels(string s) {
        int l=0,r=s.size()-1;
        string vowels="aeiouAEIOU";
        while(l<r){
            if(!vowels.contains(s[l]))      l++;
            else if(!vowels.contains(s[r]))  r--;
            else{
                swap(s[l],s[r]);
                l++,r--;
            }
        }
        return s;
    }
};