#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e7 + 5;
char s[maxn];
int dp[maxn];
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        scanf("%s", s + 1);
        int ans = 0, sum1 = 0;
        for(int i = 1; i <= n; ++i){
            dp[i] = max(0, dp[i - 1]) + (s[i] == '1' ? -1 : 1);
            if(s[i] == '1') ++sum1;
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans + sum1);
    }
    return 0;
}