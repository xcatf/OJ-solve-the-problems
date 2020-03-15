#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e3 + 5;
static const int mod = 10000;
typedef long long ll;
int dp[maxn][maxn];
int dfs(int u, int v){
    if(dp[u][v]) return dp[u][v];
    for(int i = abs(u - v) - 1; i >= 0; --i){
        dp[u][v] += dfs(v, i);
        dp[u][v] %= mod;
    }
    dp[v][u] = dp[u][v];
    return dp[u][v];
}
int main(){
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i){
        dp[i][i] = 1;
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += dfs(n, i);
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}