class Solution {
public:
    vector<int>find_pse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>find_nse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            ans[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=(int)(1e9+7);
        long long total=0;
        vector<int>pse=find_pse(arr);
        vector<int>nse=find_nse(arr);
        for(int i=0;i<arr.size();i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long contribution=left*right*1LL*arr[i]%mod;
            total=(total+contribution)%mod;
        }
        return (int)total;
    }
};