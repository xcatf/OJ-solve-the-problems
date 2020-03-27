#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
vector<int>e[maxn];
int ans[maxn][105],gs[maxn];
int n,m,k,s;
void bfs(int g){
    queue<int>q;
    for(int i=1;i<=n;++i){
        if(gs[i]==g){
            ans[i][g]=0;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<e[u].size();++i){
            int v=e[u][i];
            if(ans[v][g]==-1){
                ans[v][g]=ans[u][g]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
        for(int i=1;i<=n;++i) e[i].clear();
        memset(ans,-1,sizeof(ans));
        for(int i=1;i<=n;++i) scanf("%d",&gs[i]);
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=k;++i) bfs(i);
        for(int i=1;i<=n;++i){
            int r=0;
            sort(ans[i]+1,ans[i]+k+1);
            for(int j=1;j<=s;++j) r+=ans[i][j];
            printf("%d%c",r,i==n?'\n':' ');
        }
    }
    return 0;
}   