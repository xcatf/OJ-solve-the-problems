#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
static const double eps = 1e-4;
vector<int>e[maxn];
bool vis[maxn],used[maxn];
int n,m,p;
int ans=1;
void dfs(int u,int cnt){
    if(cnt>p) return ;
    vis[u]=1;
    if(!used[u]){
        ++ans;
        used[u]=1;
    }
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if(!vis[v]) dfs(v,cnt+1);
    }
}
int main(){
    // freopen("C4.in","r",stdin);
    // freopen("C4.out","w",stdout);
    scanf("%d%d%d", &n,&m,&p);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=0;i<e[1].size();++i){
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        dfs(e[1][i],1);
    }
    printf("%d\n",ans);
    return 0;
}