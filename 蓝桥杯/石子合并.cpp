#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e3 + 5;
int sum[maxn];
int dp[maxn][maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int val;
        scanf("%d", &val);
        sum[i] = sum[i - 1] + val;
    }
    for(int k = 2; k <= n; ++k){
        for(int i = 1; i <= n - k + 1; ++i){
            int j = i + k - 1;
            dp[i][j] = INT_MAX;
            int tmp = sum[j] - sum[i - 1];
            for(int t = i; t < j; ++t){
                dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j] + tmp);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}