class Solution {
public:
    static bool comp(vector<int>&val1,vector<int>&val2){
        return val1[1]<val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int last_end_time=intervals[0][1],cnt=1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=last_end_time){
                cnt++;
                last_end_time=intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};