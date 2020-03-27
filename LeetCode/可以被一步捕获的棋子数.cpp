class Solution {
public:
    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int numRookCaptures(vector<vector<char>>& board) {
        int sx,sy;    
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(board[i][j]=='R'){
                    sx=i;
                    sy=j;
                    break;
                }
            }
        }
        int ans=0;
        for(int t=0;t<4;++t){
            int i=sx,j=sy;
            while(i>=0&&i<8&&j>=0&&j<8&&board[i][j]!='B'){
                if(board[i][j]=='p'){
                    ++ans;
                    break;
                }
                i=i+d[t][0],j=j+d[t][1];
            }
        }
        return ans;
    }
};