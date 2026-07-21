class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        unordered_map<int,int>mpp;
        vector<int>ans;
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]]=-1;
            }
            else{
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int j=0;j<n;j++){
            ans.push_back(mpp[nums1[j]]);
        }
        return ans;
    }
};