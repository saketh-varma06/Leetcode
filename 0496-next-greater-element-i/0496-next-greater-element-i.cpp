class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            mpp[nums2[i]]=st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for(int j:nums1){
            ans.push_back(mpp[j]);
        }
        return ans;
    }
};