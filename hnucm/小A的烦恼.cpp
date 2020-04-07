#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
vector<int>e[maxn];
unordered_set<int>s[maxn];
int main(){ 
    int n,m;
    // freopen("data/in3.in","r",stdin);
    // freopen("data/in3.out","w",stdout);
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            if(!s[u].count(v)){
                e[u].push_back(v);
                s[u].emplace(v);
            }
            if(!s[v].count(u)){
                e[v].push_back(u);
                s[v].emplace(u);
            } 
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<e[i].size();++j){
                printf("%d%c",e[i][j],j==e[i].size()-1?'\n':' ');
            }
        }
        for(int i=1;i<=n;++i){
            e[i].clear();
            s[i].clear();
        }
    }
    return 0;
}