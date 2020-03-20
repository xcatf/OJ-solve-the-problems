#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
struct node{
    int a,b;
    bool operator<(const node&rhs)const{
        return a-b>rhs.a-rhs.b;
    }
}p[maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i) scanf("%d%d",&p[i].a,&p[i].b);
        sort(p,p+n);
        ll ans=0;
        for(int i=0;i<n;++i){
            ans+=(ll)i*p[i].a+(ll)(n-i-1)*p[i].b;
        }
        printf("%lld\n",ans);
    }
    return 0;
}