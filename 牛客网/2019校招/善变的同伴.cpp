#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
int dp[N],a[N];
int main(){
    int n,m,v;
    scanf("%d%d",&n,&m);
    int c=1;
    for(int i=1;i<=n;++i){
        scanf("%d",&v);
        if(c==1) a[c++]=v;
        else{
            if(v*a[c-1]>=0) a[c-1]+=v;
            else a[c++]=v; 
        }
    }
    n=c-1;
    int ans=0;
    for(int i=1;i<=m;++i){
        int sum=0;
        for(int j=1;j<i;++j) sum+=a[j];
        int t=sum;
        for(int j=i;j<=n;++j){
            sum=max(dp[j-1],sum)+a[j];
            dp[j-1]=t;
            t=max(t,sum);
        }
        ans=max(t,ans);
    }
    printf("%d\n",ans);
    return 0;
}