#define pir pair<int,int>
#define mk make_pair
class Solution {
public:
    int d[4][2]={1,0,-1,0,0,1,0,-1};
    void dfs(int x,int y,int &ans,int n,int m,vector<vector<int>>&grid){
        stack<pir>st;
        st.push(mk(x,y));
        int cnt=0;
        grid[x][y]=0;
        while(!st.empty()){
            pir now=st.top();
            st.pop();
            ++cnt;
            auto [ux,uy]=now;
            for(int i=0;i<4;++i){
                int nx=ux+d[i][0];
                int ny=uy+d[i][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    st.emplace(mk(nx,ny));
                }
            }
        }
        ans=max(ans,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        bool f=1;
        for(int i=0;i<n&&f;++i){
            for(int j=0;j<m&&f;++j){
                if(grid[i][j]==1){
                    dfs(i,j,ans,n,m,grid);
                    if((n-i-1)*m+(m-1-j)<ans) f=0;
                }
            }
        }
        return ans;
    }   
};