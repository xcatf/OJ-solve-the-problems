#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=2e5+5;
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    ll p=a[1],s=a[n];
    int i=1,j=n;
    ll ans=0;
    while(i<=j){
        if(p==s) ans=s;
        if(p<=s) p+=a[++i];
        else s+=a[--j];
    }
    printf("%lld\n",ans);
    return 0;
}