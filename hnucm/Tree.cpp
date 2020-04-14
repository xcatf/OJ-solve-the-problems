#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
vector<int>e[maxn];
bool vis[maxn];
int n,k;
bool fg;
int dfs(int u,int f){
    if(!fg) return 0;
    vis[u]=1;
    int cnt=1;
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if(v==f) continue;
        if(!vis[v]){
            cnt+=dfs(v,u);
        }
    }
    if(cnt>k){
        fg=0;
        return 0;
    }
    return cnt%k;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i){
            e[i].clear();
            vis[i]=0;
        }
        for(int i=1;i<n;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        fg=1;
        dfs(1,0);
        puts(fg?"YES":"NO");
    }
    return 0;
}