#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int dp[45];
int n,w;
int main(){
    scanf("%d",&n);
    dp[0]=1;
    for(int i=0;i<n;++i){
        scanf("%d",&w);
        for(int j=40;j>=w;--j){
            dp[j]+=dp[j-w];
        }
    }
    printf("%d\n",dp[40]);
    return 0;
}