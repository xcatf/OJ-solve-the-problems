#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
int w[maxn];
ll dp[maxn];
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i) scanf("%d", &w[i]);
        dp[1] = w[1];
        w[n + 1] = 0;
        for(int i = 2; i <= n + 1; ++i){
            dp[i] = min(dp[i - 1], dp[i - 2]) + w[i];
        }
        printf("%lld\n", dp[n + 1]);
    }
    return 0;
}