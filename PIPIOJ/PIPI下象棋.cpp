#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
const int mod=1e9+7;
vector<int>e[maxn];
int col[maxn];
bool fg;
void dfs(int u){
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if(col[v]!=-1){
            if(col[u]==col[v]) fg=0;
        }
        if(col[v]==-1){
            col[v]=col[u]^1;
            dfs(v);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(col,-1,sizeof(col));
    fg=1;
    col[1]=0;
    dfs(1);
    puts(fg?"YES":"NO");
    return 0;
}