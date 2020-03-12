#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e5 + 5;
vector<int>e[maxn];
int pre[maxn];
bool used[maxn];
bool fg;
int cnt, n;
int ans[maxn];
void dfs(int u, int p){
    if(fg) return ;
    used[u] = 1;
    for(int i = 0; i < e[u].size(); ++i){
        if(fg) return;
        int v = e[u][i];
        if(v == p) continue;
        pre[v] = u;
        if(used[v]){
            int f = v;
            while(pre[f] != v){
                ans[cnt++] = f;
                f = pre[f];
            }
            ans[cnt++] = f;
            fg = 1;
            return ;
        }
        dfs(v, u);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) pre[i] = i;
    for(int i = 1; i <= n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0);
    sort(ans, ans + cnt);
    for(int i = 0; i < cnt; ++i) printf("%d%c", ans[i], i == cnt - 1 ? '\n' : ' ');
    return 0;
}