#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int ans[5];
int main(){
    // freopen("data/digital4.in","r",stdin);
    // freopen("data/digital4.out","w",stdout);
    int n,v;
    scanf("%d",&n);
    int f=1;
    int cnt=0;
    for(int i=0;i<n;++i){
        scanf("%d",&v);
        int r=v%5;
        if(r==0&&v%2==0) ans[0]+=v;
        else if(r==1) ans[1]+=f*v,f=-f;
        else if(r==2) ans[2]++;
        else if(r==3) ans[3]+=v,++cnt;
        else if(r==4) ans[4]=max(ans[4],v);
    }
    if(!ans[0]) putchar('N');
    else printf("%d",ans[0]);
    for(int i=1;i<5;++i){
        if(!ans[i]) printf(" N");
        else{
            if(i==3) printf(" %.1f",ans[i]*1.0/cnt);
            else printf(" %d",ans[i]);
        }
    }
    return 0;
}