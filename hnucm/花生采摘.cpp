#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll mod=7777777;
const int maxn=405;
struct node{
    int x,y,val;
    bool operator<(const node&r)const{
        return val>r.val;
    }
}a[maxn];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int v;
            scanf("%d",&v);
            if(v){
                a[cnt].x=i;
                a[cnt].y=j;
                a[cnt++].val=v;
            }
        }
    }
    sort(a,a+cnt);
    int ans=0;
    int px=0,py=a[0].y,pt=0;
    for(int i=0;i<cnt;++i){
        int t=abs(a[i].x-px)+abs(a[i].y-py);
        if(k>=t+a[i].x+1){
            px=a[i].x;
            py=a[i].y;
            ans+=a[i].val;
            k-=t+1;
        }
        else break;
    }
    printf("%d\n",ans);
    return 0;
}