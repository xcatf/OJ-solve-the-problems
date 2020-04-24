#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int val[maxn];
struct edge{
    int to,next;
}e[maxn];
int head[maxn];
int cnt;
void addEdge(int u,int v){
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u,int node){
    if(val[u]) return;
    val[u]=node;
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].to;
        dfs(v,node);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(v,u);
    }
    for(int i=n;i>=1;--i){
        if(val[i]==0) dfs(i,i); 
    }
    for(int i=1;i<=n;++i) printf("%d%c",val[i],i==n?'\n':' ');
    return 0;
}