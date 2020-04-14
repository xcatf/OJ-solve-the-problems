#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int dp[maxn];
int main(){
    int n,v;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) dp[i]=INT_MAX;
    int cnt=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&v);
        v-=i;
        int p=upper_bound(dp+1,dp+n+1,v)-dp;
        dp[p]=v;
        cnt=max(p,cnt);
    }
    printf("%d\n",n-cnt);
    return 0;
}