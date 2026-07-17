class Solution {
public:
    int max_element(vector<vector<int>>& mat,int n,int m,int col){
        int idx=-1,max_el=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>max_el){
                max_el=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int l=0,h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int row=max_element(mat,n,m,mid);
            int left=mid-1>=0 ? mat[row][mid-1] : -1;
            int right=mid+1<m ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};