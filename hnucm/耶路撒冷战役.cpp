#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=2e3+5;
int r[maxn],c[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;++i) scanf("%d",&r[i]);
    for(int i=0;i<m-1;++i) scanf("%d",&c[i]);
    sort(r,r+n-1,greater<int>());
    sort(c,c+m-1,greater<int>());
    int i=0,j=0,cntx=1,cnty=1;
    int ans=0;
    while(i<n-1||j<m-1){
        if(i<n-1&&r[i]>=c[j]){
            ++cntx;
            ans+=cnty*r[i++];
        }
        else{
            ++cnty;
            ans+=cntx*c[j++];
        }
    }
    printf("%d\n",ans);
    return 0;
}