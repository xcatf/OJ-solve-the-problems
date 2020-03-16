#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e3 + 5;
static const int mod = 1000000007;
typedef long long ll;
int n, m, k;
int c[55][55];
ll dp[55][55][15][15];
ll dfs(int x, int y, int cnt, int val){
    if(dp[x][y][cnt][val+1] != -1) return dp[x][y][cnt][val+1];
    ll res = 0;
    if(x == n && y == m){
        if(cnt == k || cnt == k - 1 && c[n][m] > val){
            dp[x][y][cnt][val+1] = 1;
            return 1;
        }
        else{
            dp[x][y][cnt][val+1] = -1;
            return 0;
        }
    }
    if(x+1 <= n){
        if(c[x][y] > val){
            res += dfs(x+1, y, cnt+1, c[x][y])%mod;
            res %= mod;
        }
        res += dfs(x+1, y, cnt, val);
        res %= mod;
    }
    if(y+1 <= m){
        if(c[x][y] > val){
            res += dfs(x, y+1, cnt+1, c[x][y])%mod;
            res %= mod;
        }
        res += dfs(x, y+1, cnt, val)%mod;
        res %= mod;
    }
    return dp[x][y][cnt][val+1] = res;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j) scanf("%d", &c[i][j]);
    }
    printf("%lld\n",dfs(1,1,0,-1));
    return 0;
}