class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long sum=0,k=(long long)k1+k2;
        int i=0,n=nums1.size();
        vector<int>diff(n);
        while(i<n){
            diff[i]=abs(nums1[i]-nums2[i]);
            sum+=diff[i];
            i++;
        }
        if(sum<=k){
            return 0;
        }
        int l=0,h=*max_element(diff.begin(),diff.end());
        while(l<h){
            long long mid=l+(h-l)/2;
            long long need=0;
            int i=0;
            while(i<diff.size()){
                if(diff[i]>mid){
                    need+=diff[i]-mid;
                }
                i++;
            }
            if(need<=k){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        long long used=0;
        i=0;
        while(i<diff.size()){
            if(diff[i]>l){
                used+=diff[i]-l;
                diff[i]=l;
            }
            i++;
        }
        k-=used;
        i=0;
        while(i<diff.size() && k>0){
            if(diff[i]==l && diff[i]>0){
                diff[i]--;
                k--;
            }
            i++;
        }
        i=0,sum=0;
        while(i<diff.size()){
            sum+=1LL*diff[i]*diff[i];
            i++;
        }
        return sum;
    }
};