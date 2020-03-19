#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int a[25][25];
struct node{
    int x,y,v;
    bool operator<(const node x)const{
        return v>x.v;
    }
};
node w[405];
int cnt;
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                w[++cnt].x=i;
                w[cnt].y=j;
                w[cnt].v=a[i][j];
            }
        }
    }
    sort(w+1,w+n+1);
    if(k<w[1].x*2+1){
        printf("0\n");
    }else{
        int now=w[1].x+1,ans=w[1].v;
        for(int i=1;i<n;++i){
            int l=abs(w[i+1].x-w[i].x)+abs(w[i+1].y-w[i].y)+1;
            if(now+l+w[i+1].x<=k){
                now+=l;
                ans+=w[i+1].v;
            }else{
                break;
            }
        }
        printf("%d\n",ans);
    }
}