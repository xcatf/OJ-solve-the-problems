#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int in[maxn];
vector<int>e[maxn];
void solve(int n){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;++i){
        if(in[i]==0) pq.emplace(i);
    }
    int cnt=0;
    while(!pq.empty()){
        int u=pq.top();
        pq.pop();
        ++cnt;
        printf("Task%d%c",u,cnt==n?'\n':' ');
        for(int i=0;i<e[u].size();++i){
            int v=e[u][i];
            if(--in[v]==0){
                pq.emplace(v);
            }
        }
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            e[i].clear();
            in[i]=0;
        }
        for(int i=0;i<n;++i){
            int u,v;
            char op;
            scanf(" Task%d",&u);
            while(~scanf("%c",&op)){
                if(op==')') break;
                if(op=='T'){
                    scanf("ask%d",&v);
                    in[v]++;
                    e[u].push_back(v);
                }
            }
        }
        solve(n);
    }
    return 0;
}