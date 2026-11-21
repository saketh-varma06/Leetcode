class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>pp;
        vector<int>res;
        int l=0,r=0;
        if (p.size() > s.size()) return res;
        for(auto ch:p){
            pp[ch]++;
        }
        while(r<p.size()){
            mpp[s[r]]++;
            r++;
        }
        if(mpp==pp){
            res.push_back(l);
        }
        while (r < s.size()) {
            mpp[s[r]]++;          
            mpp[s[l]]--;          

            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);  

            l++;
            r++;

            if (mpp == pp) {
                res.push_back(l);
            }
        }

        return res;
    }
};