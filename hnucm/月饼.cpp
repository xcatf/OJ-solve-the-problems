#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
struct node{
    double a,b;
    bool operator<(const node&r)const{
        return b*r.a>a*r.b;
    }
}v[maxn];
int main(){
    int n;
    double d;
    scanf("%d%lf",&n,&d);
    for(int i=0;i<n;++i) scanf("%lf",&v[i].a);
    for(int i=0;i<n;++i) scanf("%lf",&v[i].b);
    sort(v,v+n);
    double ans=0;
    for(int i=0;i<n;++i){
        if(v[i].a<=d){
            ans+=v[i].b;
            d-=v[i].a;
        }
        else{
            ans+=d*v[i].b/v[i].a;
            break;
        }
    }
    printf("%.2f\n",ans);
    return 0;
}