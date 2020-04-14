#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int n,m;
vector<int>e[maxn];
int col[maxn];
bool vis[maxn];
bool ok1,ok2;
void dfs(int u,int fa){
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if(v==fa) continue;
        if(col[v]!=-1){
            if(col[u]==col[v]) ok1=1;
            else ok2=1;
        }
        if(!vis[v]){
            vis[v]=1;
            col[v]=col[u]^1;
            dfs(v,u);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=0;i<m;++i){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(col,-1,sizeof(col));
    ok1=0;
    ok2=0;
    int ans=-1;
    for(int i=1;i<=n;++i){
        if(col[i]==-1){
            ++ans;
            col[i]=0;
            dfs(i,0);
        }
        if(i==1) ok2=0;
    }
    if(ok1==0&&ok2==0) ++ans;   //所有联通块中无环
    if(ok1==0&&ans==0) ++ans;   //只存在起点一个联通块且无奇环
    printf("%d\n",ans);
    return 0;
}