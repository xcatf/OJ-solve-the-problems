#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 5e3 + 5;
int a[maxn];
int dp[maxn];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if(k >= n / 2){
        int ans = 0;
        for(int i = 1; i < n; ++i){
            if(a[i] > a[i - 1]) ans += a[i] - a[i - 1];
        }
        printf("%d\n", ans);
        return 0;
    }
    for(int i = 0; i < 2 * k; ++i) dp[i] = INT_MIN;
    dp[0] = -a[0];
    for(int i = 1; i < n; ++i){
        dp[0] = max(dp[0], -a[i]);
        for(int j = 1; j < 2 * k; ++j){
            if(j & 1) dp[j] = max(dp[j], dp[j - 1] + a[i]);
            else dp[j] = max(dp[j], dp[j - 1] - a[i]);
        }
    }
    printf("%d\n", max(dp[2 * k - 1], 0));
    return 0;
}