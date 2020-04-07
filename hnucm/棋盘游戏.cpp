#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=5e3+5;
int mp[6][6];
int d[4][2]={1,0,-1,0,0,-1,0,1};
bool vis[6][6];
int ex,ey;
void dfs(int x,int y,int now,int st,int &ans){
    if(x==ex&&y==ey){
        ans=min(ans,now);
        return ;
    }
    if(now>=ans) return ;
    for(int i=0;i<4;++i){
        int nx=x+d[i][0];
        int ny=y+d[i][1];
        if(nx>=0&&nx<6&&ny>=0&&ny<6&&!vis[nx][ny]){
            vis[nx][ny]=1;
            dfs(nx,ny,now+st*mp[nx][ny],st*mp[nx][ny]%4+1,ans);
            vis[nx][ny]=0;
        }
    }
}
int main(){
    // freopen("data/board6.in","r",stdin);
    // freopen("data/board6.out","w",stdout);
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j) scanf("%d",&mp[i][j]);
    }
    int sx,sy;
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    int ans=INT_MAX;
    vis[sx][sy]=1;
    dfs(sx,sy,0,1,ans);
    printf("%d\n",ans);
    return 0;
}