#include<bits/stdc++.h>
class Solution {
public:
    int calculatenoofdays(vector<int>& weights,int capacity){
        int days=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);     //accumulate for sum in c++ stl;
        while(l<=h){
            int mid=l+(h-l)/2;
            int noofdays=calculatenoofdays(weights,mid);
            if(noofdays<=days){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};