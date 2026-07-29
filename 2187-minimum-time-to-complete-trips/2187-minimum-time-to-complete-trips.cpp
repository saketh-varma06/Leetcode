class Solution {
public:
    bool totaltripsbuscomplete(vector<int>& time,long long mid,int trips){
        long long tot_time=0;
        for(int i=0;i<time.size();i++){
            long long tot=mid/time[i];
            tot_time+=tot;
        }
        return tot_time>=trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1,h=1LL*(*min_element(time.begin(),time.end()))*totalTrips;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(totaltripsbuscomplete(time,mid,totalTrips)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};