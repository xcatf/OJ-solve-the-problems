#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+3;
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    int cnt=0,i=0,j=n-1;
    ll ans=0;
    while(i<=j){
        if(a[i]>=a[j]) ans+=a[i++];
        else ans+=a[j--];
        ans-=cnt;
        ++cnt;
    }
    printf("%lld",ans);
    return 0;
}