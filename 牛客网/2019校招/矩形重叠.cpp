#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int lx[55],rx[55],ly[55],ry[55];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&lx[i]);
    for(int i=0;i<n;++i) scanf("%d",&ly[i]);
    for(int i=0;i<n;++i) scanf("%d",&rx[i]);
    for(int i=0;i<n;++i) scanf("%d",&ry[i]);
    int ans=0;
    for(int j=0;j<n;++j){
        for(int k=0;k<n;++k){
            int t=0;
            for(int i=0;i<n;++i){
                if(lx[j]>=lx[i]&&lx[j]<rx[i]){
                    if(ly[k]>=ly[i]&&ly[k]<ry[i]) ++t;
                }
            }
            ans=max(ans,t);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
6
30 20 10 20 10 0
5 15 20  35 40 40
40 50 15 50 15 5
10 30 29 50 40 40
*/