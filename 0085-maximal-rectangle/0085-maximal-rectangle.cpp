class Solution {
public:
    int largest_rectangle_area(vector<int>& p_sum){
        int n=p_sum.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && p_sum[st.top()] > p_sum[i]){
                int el=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1 : st.top();
                maxi=max(maxi,(nse-pse-1)*p_sum[el]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty() ? -1 : st.top();
            maxi=max(maxi,(nse-pse-1)*p_sum[el]);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0)    return 0;
        int m=matrix[0].size(),max_area=0;
        vector<vector<int>> prefix_sum(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum=0;
                prefix_sum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            max_area=max(max_area,largest_rectangle_area(prefix_sum[i]));
        }
        return max_area;
    }
};