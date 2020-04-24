#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=2e5+5;
ll a[maxn];
int main(){
    int n,k,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;++i){
            int p=upper_bound(a+i+1,a+n+1,a[i]+k)-a-1;
            ans=max(p-i+1,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}