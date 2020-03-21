#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e3 + 5;
static const double eps = 1e-4;
int t[maxn], v[maxn];
int dp[maxn];
int main(){
    int T, m;
    //freopen("D.in", "r", stdin);
    //freopen("D.out", "w", stdout);
    while(scanf("%d%d", &T, &m) != EOF){
       memset(dp, 0, sizeof(dp));
       for(int i = 0; i < m; ++i) scanf("%d%d", &t[i], &v[i]);
       for(int i = 0; i < m; ++i){
           for(int j = T; j >= t[i]; --j){
               dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
           }
       }
       printf("%d\n", dp[T]);
   }
}