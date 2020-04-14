#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
int dp[maxn][55];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int cas, B, M;
        scanf("%d%d%d", &cas, &B, &M);
        memset(dp, 127, sizeof(dp));
        for(int i = 0; i <= B; ++i) dp[0][i] = 0;
        for(int i = 1; i <= M; ++i){
            for(int j = 1; j <= B; ++j){
                for(int k = 1; k <= i; ++k){
                    dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
                }
            }
        }
        printf("%d %d\n", cas, dp[M][B]);
    }
}