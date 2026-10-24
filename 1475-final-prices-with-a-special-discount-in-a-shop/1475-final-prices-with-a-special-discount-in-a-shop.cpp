class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>nse(n);
        for(int i=0;i<prices.size();i++){
            nse[i]=prices[i];
        }
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(!st.empty())      nse[i]=prices[i]-st.top();
            st.push(prices[i]); 
        }
        return nse;
    }
};