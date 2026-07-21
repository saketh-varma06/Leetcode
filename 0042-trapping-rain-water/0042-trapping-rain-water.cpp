class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l_max=0,r_max=0,l=0,r=n-1,total=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(l_max>height[l]){
                    total+=l_max-height[l];
                }
                else{
                    l_max=height[l];
                }
                l++;
            }
            else{
                if(r_max>height[r]){
                    total+=r_max-height[r];
                }
                else{
                    r_max=height[r];
                }
                r--;
            }
        }
        return total;
    }
};