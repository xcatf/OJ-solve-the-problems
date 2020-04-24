#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
ll p1[maxn],p2[maxn],p3[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            p1[l]++;
            p1[r+1]--;
        }
        else{
            p3[l]++;
            p3[r+1]--;
            p2[r+1]-=r-l+1;
        }
    }
    for(int i=1;i<=n;++i){
        p1[i]+=p1[i-1]; 
        p3[i]+=p3[i-1];
        p2[i]+=p2[i-1]+p3[i];
        printf("%lld%c",p1[i]+p2[i],i==n?'\n':' ');
    }
    return 0;
}