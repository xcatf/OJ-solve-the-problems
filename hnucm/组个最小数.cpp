#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int ans[10];
int main(){
    // freopen("data/minimum5.in","r",stdin);
    // freopen("data/minimum5.out","w",stdout);
    for(int i=0;i<=9;++i) scanf("%d",&ans[i]);
    if(ans[0]){ 
        for(int i=1;i<=9;++i){
            if(ans[i]){
                printf("%d",i);
                --ans[i];
                break;
            }
        }
    }
    for(int i=0;i<=9;++i){
        for(int j=0;j<ans[i];++j) printf("%d",i);
    }
}