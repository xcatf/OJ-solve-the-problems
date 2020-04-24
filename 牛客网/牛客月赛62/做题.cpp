#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=5e5+5;
int a[maxn];
int main(){
    int n;
    ll m;
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;++i){
        if(m>=a[i]){
            ++ans;
            m-=a[i];
        }
        else break;
    }
    printf("%d\n",ans);
    return 0;
}