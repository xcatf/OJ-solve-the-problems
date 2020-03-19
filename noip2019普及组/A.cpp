#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int main(){
    // freopen("data/A4.in","r",stdin);
    // freopen("data/A4.out","w",stdout);
    int ans=0,x;
    for(int i=1;i<=7;++i){
        scanf("%d",&x);
        if(x/10+x%10>8&&ans==0){
            ans=i;
        }
    }
    printf("%d\n",ans);
}