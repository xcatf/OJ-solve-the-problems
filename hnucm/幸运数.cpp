#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=4e6+5;
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    ll s;
    scanf("%lld",&s);
    ll sum=0;
    int ans=0;
    int i;
    for(i=1;i<=n&&sum<s;++i){
        ans++;
        sum+=a[i];
    }
    for(;i<=n;++i){
        sum+=a[i];
        sum-=a[i-ans];
        if(sum-a[i-ans+1]>=s){
            sum-=a[i-ans+1];
            --ans;
        }
    }
    printf("%d\n",ans);
}