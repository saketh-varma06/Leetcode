class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;
        vector<int> win(26, 0), pat(26, 0);
        for (char ch : p)
            pat[ch - 'a']++;

        int l = 0, r = 0;
        while (r < p.size()) {
            win[s[r] - 'a']++;
            r++;
        }
        if (win == pat)
            res.push_back(l);
        while (r < s.size()) {
            win[s[r] - 'a']++;   
            win[s[l] - 'a']--;  
            l++;
            r++;
            if (win == pat)
                res.push_back(l);
        }
        return res;
    }
};