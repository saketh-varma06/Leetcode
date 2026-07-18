class Solution {
public:
    bool ballsweplace(vector<int>& position, int dist,int m){
        int cntballs=1,last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=dist){
                cntballs++;
                last=position[i];
            }
        }
        if(cntballs>=m)   return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size(),ans=-1;
        int l=1,h=position[n-1]-position[0];
        while(l<=h){
            int mid=l+(h-l)/2;
            if(ballsweplace(position,mid,m)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};