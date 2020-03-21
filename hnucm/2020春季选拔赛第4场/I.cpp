#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
vector<pair<int, bool> >edge[maxn];
char s1[maxn], s2[maxn];
bool used[maxn];
int ans;
bool dfs(int u, bool state){
    used[u] = 1;
    int cnt = 0;
    for(int i = 0; i < edge[u].size(); ++i){
        int v = edge[u][i].first;
        if(used[v]) continue;
        if(dfs(v, edge[u][i].second)) ++cnt;
    }
    ans += cnt / 2;
    return cnt % 2 == 1 || state;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        scanf("%s%s", s1, s2);
        for(int i = 0; i < n - 1; ++i){
            int u, v;
            scanf("%d%d", &u, &v);
            if(s1[i] == '0' && s2[i] == '1') continue;
            bool f = (s2[i] == '1');
            edge[u].push_back(make_pair(v, f));
            edge[v].push_back(make_pair(u, f));
        }
        ans = 0;
        for(int i = 1; i <= n; ++i){
            if(dfs(i, false)) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}