#include <bits/stdc++.h>
using namespace std;
static const int maxn = 55;
typedef long long ll;
static const int mod = 1e9+7;
ll dp[55][55][15][15];
int c[55][55];
int n, m, k;
ll dfs(int x, int y, int cnt, int val){
    if(dp[x][y][cnt][val+1] != -1) return dp[x][y][cnt][val+1];
    if(x==n && y==m){
        if(cnt==k || cnt==k-1 && c[x][y]>val){
            dp[x][y][cnt][val+1]=1;
            return 1;
        }
        else{
            dp[x][y][cnt][val+1]=-1;
            return 0;
        }
    }
    ll ans=0;
    if(x+1 <= n){
        if(c[x][y]>val){
            ans+=dfs(x+1,y,cnt+1,c[x][y])%mod;
        }
        ans+=dfs(x+1,y,cnt,val)%mod;
    } 
    if(y+1 <= m){
        if(c[x][y]>val){
            ans+=dfs(x,y+1,cnt+1,c[x][y])%mod;
        }
        ans+=dfs(x,y+1,cnt,val)%mod;
    }
    return dp[x][y][cnt][val+1] = ans%mod;
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) scanf("%d",&c[i][j]);
    }
    printf("%lld\n",dfs(1,1,0,-1));
    return 0;
}