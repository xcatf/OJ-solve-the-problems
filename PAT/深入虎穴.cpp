#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int d[maxn];
int ind[maxn];
vector<int>e[maxn];
int bfs(int s){
    queue<int>q;
    q.emplace(s);
    d[s]=1;
    int r=s;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int le=e[u].size();
        for(int i=0;i<le;++i){
            int v=e[u][i];
            if(!d[v]){
                d[v]=d[u]+1;
                if(d[v]>d[r]) r=v;
                q.emplace(v);
            }
        }
    }
    return r;
}
int main(){
    int n,m,v;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&m);
        for(int j=0;j<m;++j){
            scanf("%d",&v);
            ind[v]++;
            e[i].push_back(v);
            e[v].push_back(i);
        }
    }
    int s=1;
    for(int i=1;i<=n;++i){
        if(!ind[i]){
            s=i;
            break;
        }
    }
    printf("%d\n",bfs(s));
    return 0;
}