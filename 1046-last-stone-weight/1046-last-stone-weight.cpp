class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            for(int i=stones.size()-1;i>0;i--){
                if(stones[i]!=stones[i-1]){
                    stones[i-1]=stones[i]-stones[i-1];
                    stones.erase(stones.begin()+i);
                }
                else{
                    stones.erase(stones.begin()+i);
                    stones.erase(stones.begin()+i-1);
                }
                break;
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};