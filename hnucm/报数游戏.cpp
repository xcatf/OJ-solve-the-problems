#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ysf(int n,int m,int i)
{
    if(i==1)
        return (n+m-1)%n;
    else
        return (ysf(n-1,m,i-1)+m)%n;
}
int main(){
    int n,m;
    // freopen("E4.in","r",stdin);
    // freopen("E4.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int i;
        for(i=1;i<=n;++i){
            if(ysf(n,m,i)%n==0) break;
        }
        printf("%d\n",i-1);
    }
    return 0;
}