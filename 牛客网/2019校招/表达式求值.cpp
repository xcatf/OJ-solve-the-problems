#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    int a[3];
    for(int i=0;i<3;++i) scanf("%d",&a[i]);
    sort(a,a+3);
    int ans=max(a[0]*a[1],a[0]+a[1]);
    ans=max(a[2]*ans,a[2]+ans);
    printf("%d\n",ans);
    return 0;
}