class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=st.top();
                st.pop();   
                int nse=i;
                int pse=st.empty() ? -1 : st.top();
                maxi=max(maxi,(nse-pse-1)*heights[el]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=st.top();
            st.pop(); 
            int nse=n;
            int pse=st.empty() ? -1 : st.top();
            maxi=max(maxi,(nse-pse-1)*heights[el]);
        }
        return maxi;
    }
};