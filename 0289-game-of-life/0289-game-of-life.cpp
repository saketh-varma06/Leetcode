class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dup=board;
        int n=board[0].size(),m=board.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x==0 && y==0){
                            continue;
                        }
                        int r=i+x;
                        int c=j+y;
                        if(r>=0 && r<m && c>=0 && c<n){
                            if(dup[r][c]==1){
                                cnt++;
                            }
                        }
                    }
                }
                if(dup[i][j]==1){
                    if(cnt<2 || cnt>3){
                        board[i][j]=0;
                    } 
                }
                else{
                    if(cnt==3){
                        board[i][j]=1;
                    }
                }
            }
        }
    }
};