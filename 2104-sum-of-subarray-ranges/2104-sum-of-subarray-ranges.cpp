class Solution {
public: 
    vector<int>find_pge(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>find_nge(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>nums[st.top()]){
                st.pop();
            }
            ans[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sub_array_maximums(vector<int>& nums){
        vector<int>pge=find_pge(nums);
        vector<int>nge=find_nge(nums);
        long long total=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            long long contribution=left*right*1LL*nums[i];
            total=(total+contribution);
        }
        return total;
    }
    vector<int>find_pse(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>find_nse(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<nums[st.top()]){
                st.pop();
            }
            ans[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sub_array_minimums(vector<int>& nums){
        vector<int>pse=find_pse(nums);
        vector<int>nse=find_nse(nums);
        long long total=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long contribution=left*right*1LL*nums[i];
            total=(total+contribution);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sub_array_maximums(nums)-sub_array_minimums(nums);
    }
};