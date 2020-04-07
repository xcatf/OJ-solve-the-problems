#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
struct node{
    int x,y;
    node(){}
    node(int _x,int _y){x=_x;y=_y;}
};
char mp[maxn][maxn];
int n,m;
queue<node>q[3];
bool vis[3][maxn][maxn];
int d1[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int cnt[3]={4,4,8};
node pos[3];
bool bfs(int id){
    int sz=q[id].size();
    while(sz--){
        int cx=q[id].front().x;
        int cy=q[id].front().y;
        q[id].pop();
        for(int i=0;i<cnt[id];++i){
            int nx=cx+d1[i][0];
            int ny=cy+d1[i][1];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]=='#'||vis[id][nx][ny]) continue;
            q[id].push(node(nx,ny));
            vis[id][nx][ny]=1;
            if(vis[0][nx][ny]&&vis[1][nx][ny]&&vis[2][nx][ny]) return true;

        }
    }
    return false;
}
int solve(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<3;++i){
        while(!q[i].empty()) q[i].pop();
        q[i].push(pos[i]);
        vis[i][pos[i].x][pos[i].y]=1;
    }
    int t=0;
    while(!q[0].empty() || !q[1].empty() || !q[2].empty()){
        ++t;
        if(bfs(0)) return t;
        if(bfs(1)) return t;
        for(int k=0;k<3;++k){
            if(bfs(2)) return t;
        }
    }
    return -1;
}
int main(){
    // freopen("data/junxun0.in", "r", stdin);
    // freopen("data/junxun0.out", "w", stdout);
    char tc[3]={'z','y','h'};
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i=0;i<n;++i) scanf("%s",mp[i]);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                for(int id=0;id<3;++id){
                    if(mp[i][j]==tc[id]){
                        pos[id].x=i;
                        pos[id].y=j;
                        break;    
                    }
                }
            }
        }
        int ans=solve();
        if(ans!=-1) printf("%d\n",ans);
        else puts("lack of junxun");
    }
    return 0;
}