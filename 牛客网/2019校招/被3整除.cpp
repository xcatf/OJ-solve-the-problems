#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    int l,r;
    scanf("%d%d",&l,&r);
    int ans=0;
    int c1=(r-l+1)/3;
    ans+=c1*2;
    for(int i=l+c1*3;i<=r;++i){
        if(i%3!=1) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}