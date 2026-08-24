class Solution {
public:
    static bool comp(vector<int>&val1,vector<int>&val2){
        return val1[1]>val2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int total_cost=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                total_cost+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else{
                total_cost+=boxTypes[i][1]*truckSize;
                break;
            }
        }
        return total_cost;
    }
};