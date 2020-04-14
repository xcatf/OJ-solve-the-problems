#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e2+5;
int t[maxn];
int main(){
    int n,h,m;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&h,&m);
        t[i]=h*60+m;
    }
    int x;
    scanf("%d",&x);
    scanf("%d%d",&h,&m);
    int now=h*60+m-x,ans=0;
    for(int i=0;i<n;++i){
        if(t[i]<=now){
            ans=max(ans,t[i]);
        }
    }
    printf("%d %d\n",ans/60,ans%60);
    return 0;
}