class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),comp);
        int m=queries.size();
        vector<pair<int,int>>qr;
        for(int i=0;i<m;i++){
            qr.push_back({queries[i],i});
        }
        sort(qr.begin(),qr.end());
        vector<int>ans(m);
        unordered_map<int,int>mpp;
        int left=0,right=0,active=0;
        for(int i=0;i<m;i++){
            int start=qr[i].first-x;
            int end=qr[i].first;
            while(right<logs.size() && logs[right][1]<=end){
                int id=logs[right][0];
                if(mpp[id]==0){
                    active++;
                }
                mpp[id]++;
                right++;
            }
            while(left<right && logs[left][1]<start){
                int id=logs[left][0];
                mpp[id]--;
                if(mpp[id]==0){
                    active--;
                }
                left++;
            }
            ans[qr[i].second]=n-active;
        }
        return ans;
    }
};