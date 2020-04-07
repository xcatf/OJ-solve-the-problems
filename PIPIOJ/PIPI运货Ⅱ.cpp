#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e3 + 5;
int n,m;
int a[maxn][maxn];
int main(){
    scanf("%d%d",&n,&m);
    int maxl=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
            maxl=max(maxl,a[i][j]);
        }
    }
    int c=0;
    ll x=0,y=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]==maxl){
                x+=i;
                y+=j;
                c++;
            }
        }
    }
    x/=c;
    y/=c;
    ll ans=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans+=(abs(x-i)+abs(y-j))*a[i][j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}