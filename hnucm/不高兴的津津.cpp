#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int main(){
    int ans=0;
    int now=-1;
    for(int i=1;i<=7;++i){
        int v;
        scanf("%d",&v);
        int t=v/10+v%10;
        if(t>=8&&t>now){
            now=t;
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}